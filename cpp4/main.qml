import QtQuick 2.9
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import ru.vsu.csf 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    WordsMap {
        id: wordsMap
    }

    ColumnLayout {

        spacing : 10

        FileDialog {
            id: openFileDialog
            title: "Open file"
            //selectMultiple: false
            fileMode: FileDialog.OpenFile
            nameFilters: ["Text files (*.txt)"]
            onAccepted: {
                // Load file
                var fileUrl = selectedFile.toString().slice(8)                
                wordsMap.read_from_file(fileUrl)
            }
        }

        FileDialog {
            id: saveFileDialog
            title: "Save file"
            //selectMultiple: false
            fileMode: FileDialog.SaveFile
            nameFilters: ["Text files (*.txt)"]
            onAccepted: {
                var fileUrl = selectedFile.toString().slice(8)                
                wordsMap.save_into_file(fileUrl)
            }
        }

        RowLayout {
            Button {
                text: "Load words"
                onClicked: {
                    openFileDialog.open()
                }
            }


            Button {
                text: "Save map"
                onClicked: {
                   saveFileDialog.open()
                }
            }
        }

        GroupBox {

            RowLayout {
                ButtonGroup {
                    id: sortGroup
                    exclusive: true
                }

                RadioButton {
                    text: "By count"
                    checked: true
                    ButtonGroup.group: sortGroup
                }

                RadioButton {
                    text: "By alphabet"
                    ButtonGroup.group: sortGroup
                }

                Button {
                    text: "Show map"
                    onClicked: {
                        textArea.text = wordsMap.values(sortGroup.checkedButton.text.slice(3).toUpperCase())
                    }
                }
            }

        }

        
        GroupBox {
            Layout.preferredWidth: 200
            Layout.preferredHeight: 200
            Flickable {
                  id: flickable
                  anchors.fill: parent

                  TextArea.flickable: TextArea {
                            id: textArea
                            //text: "TextArea\n...\n...\n...\n...\n...\n...\nn...\n...\n...\n...\n...\n...\nn...\n...\n...\n...\n...\n...\nn...\n...\n...\n...\n...\n...\nn...\n...\n...\n...\n...\n...\n"
                            wrapMode: TextArea.Wrap
                            anchors.fill: parent
                        }
            }

            ScrollBar.vertical: ScrollBar {
                        height: 200
                  }
              }

        }
        
 

}
