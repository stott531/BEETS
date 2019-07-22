//
// Created by stott on 6/17/19.
//

#include "testSuite.h"

testSuite::testSuite(const QString &name, const QString &pathToExe) : name(name), path_to_exe(pathToExe)
{
    //initialize an empty map
    this->tests = QMap<QString, Test>();
}

testSuite::testSuite(const QString& test_name)
{
    //makes this more usable
    QString fileName = "../etc/" + test_name + ".JSON";

    //opens the file
    QFile json_file(fileName);
    json_file.open(QIODevice::ReadOnly);

    //reads all text from file in as one string
    QString raw_file = json_file.readAll();

    //close the file
    json_file.close();

    //convert QString into a JsonObject we can work with
    QJsonDocument json_doc = QJsonDocument::fromJson(raw_file.toUtf8());
    QJsonObject obj = json_doc.object();

    //iterate through all keys in the JsonObject
    for (const QString& var : obj.keys())
    {
        if (var == "name")
        {
            //if this key is "name", set our name to the corresponding value
            this->name = obj["name"].toString();
        }
        else if (var == "path_to_exe")
        {
            //if this key is "path_to_exe", set our name to the corresponding value
            this->path_to_exe = obj["path_to_exe"].toString();
        }
        else
        {
            //else the key is a test name and we need to add it to our self's map of tests
            QJsonArray temp = obj[var].toArray();

            //insert the new test at the key "var"
            this->tests[var] = Test(var, temp[0].toString(), temp[1].toString(),
                                         temp[2].toString(), temp[3].toString());
        }
    }
}

void testSuite::run_tests()
{
    for (auto& iter : this->tests.values())
    {
        iter.set_path(this->path_to_exe);
    }

    auto func = [] (Test t) -> void {t.runTest();};

    QFuture<void> future = QtConcurrent::map(this->tests.values().begin(),
                                             this->tests.values().end(),
                                             func
                                             );
}

void testSuite::serialize()
{
    QJsonObject json;

    //inserts the name and path from the testSuite into the JSON
    json.insert("name", QJsonValue(this->name));
    json.insert("path_to_exe", QJsonValue(this->path_to_exe));

    //insert each test into the JSON
    for (auto test : this->tests) {
        json.insert(test.getName(), test.toJsonValue());
    }

    //create file, writet the JSON to the file, and close
    QJsonDocument file(json);
    QString fileName ="../etc/" + this->name + ".JSON";
    QFile newFile(fileName);
    newFile.open(QIODevice::WriteOnly);
    newFile.write(file.toJson());
    newFile.close();
}

void testSuite::addTest(const QString &name, const Test &newTest)
{
    this->tests[name] = newTest;
}

void testSuite::removeTest(const QString &name)
{
    this->tests.remove(name);
}

void testSuite::updateTest(const QString &name, const Test &newTest)
{
    this->tests[name] = newTest;
}

const QMap<QString, Test>& testSuite::getTestMap() const
{
    return this->tests;
}

void testSuite::setPath_to_exe(const QString& newPath)
{
    this->path_to_exe = newPath;
}


Test testSuite::getTestAt(const QString& requestedTest)
{
    return this->tests[requestedTest];
}
