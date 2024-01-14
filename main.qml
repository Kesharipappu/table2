import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "SQLite Table in QML"

    ListView {
        width: 400
        height: 300
        model: sqlQueryModel

        delegate: Item {
            width: 400
            height: 40
            Text {
                width: 200
                text: model.name
            }
            Text {
                width: 200
                text: model.age
            }
        }
    }

    Component.onCompleted: {
        SqliteBridge.openDatabase("example1");
        var queryResult = SqliteBridge.executeQuery("SELECT * FROM student");
        sqlQueryModel.append(queryResult);
    }

    ListModel {
        id: sqlQueryModel
    }
}
