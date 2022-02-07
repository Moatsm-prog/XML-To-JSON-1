# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/media/mustafa/E:/College/Data Structure & Algo/Project/XML-To-JSON/Forms/xml_editor.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_XML_Editor(object):
    def setupUi(self, XML_Editor):
        XML_Editor.setObjectName("XML_Editor")
        XML_Editor.resize(871, 600)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/icon.ico"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        XML_Editor.setWindowIcon(icon)
        self.centralwidget = QtWidgets.QWidget(XML_Editor)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName("verticalLayout")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.splitter = QtWidgets.QSplitter(self.centralwidget)
        self.splitter.setOrientation(QtCore.Qt.Horizontal)
        self.splitter.setObjectName("splitter")
        self.verticalLayoutWidget = QtWidgets.QWidget(self.splitter)
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout_4.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.label_2 = QtWidgets.QLabel(self.verticalLayoutWidget)
        font = QtGui.QFont()
        font.setBold(True)
        self.label_2.setFont(font)
        self.label_2.setAlignment(QtCore.Qt.AlignCenter)
        self.label_2.setObjectName("label_2")
        self.verticalLayout_4.addWidget(self.label_2)
        self.input_textedit = QtWidgets.QTextEdit(self.verticalLayoutWidget)
        self.input_textedit.setLineWrapMode(QtWidgets.QTextEdit.WidgetWidth)
        self.input_textedit.setReadOnly(True)
        self.input_textedit.setObjectName("input_textedit")
        self.verticalLayout_4.addWidget(self.input_textedit)
        self.verticalLayoutWidget_2 = QtWidgets.QWidget(self.splitter)
        self.verticalLayoutWidget_2.setObjectName("verticalLayoutWidget_2")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.verticalLayoutWidget_2)
        self.verticalLayout_5.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.label = QtWidgets.QLabel(self.verticalLayoutWidget_2)
        font = QtGui.QFont()
        font.setBold(True)
        self.label.setFont(font)
        self.label.setAlignment(QtCore.Qt.AlignCenter)
        self.label.setObjectName("label")
        self.verticalLayout_5.addWidget(self.label)
        self.output_textedit = QtWidgets.QTextEdit(self.verticalLayoutWidget_2)
        self.output_textedit.setLineWrapMode(QtWidgets.QTextEdit.NoWrap)
        self.output_textedit.setReadOnly(True)
        self.output_textedit.setObjectName("output_textedit")
        self.verticalLayout_5.addWidget(self.output_textedit)
        self.horizontalLayout.addWidget(self.splitter)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.horizontalLayout_12 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_12.setSizeConstraint(QtWidgets.QLayout.SetDefaultConstraint)
        self.horizontalLayout_12.setContentsMargins(10, 10, 10, 10)
        self.horizontalLayout_12.setSpacing(10)
        self.horizontalLayout_12.setObjectName("horizontalLayout_12")
        self.verticalLayout_16 = QtWidgets.QVBoxLayout()
        self.verticalLayout_16.setContentsMargins(-1, -1, 0, -1)
        self.verticalLayout_16.setObjectName("verticalLayout_16")
        self.verticalSlider = QtWidgets.QSlider(self.centralwidget)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.verticalSlider.sizePolicy().hasHeightForWidth())
        self.verticalSlider.setSizePolicy(sizePolicy)
        self.verticalSlider.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.verticalSlider.setMinimum(5)
        self.verticalSlider.setMaximum(30)
        self.verticalSlider.setProperty("value", 9)
        self.verticalSlider.setOrientation(QtCore.Qt.Vertical)
        self.verticalSlider.setObjectName("verticalSlider")
        self.verticalLayout_16.addWidget(self.verticalSlider)
        self.horizontalLayout_12.addLayout(self.verticalLayout_16)
        self.verticalLayout_14 = QtWidgets.QVBoxLayout()
        self.verticalLayout_14.setContentsMargins(-1, 0, -1, -1)
        self.verticalLayout_14.setObjectName("verticalLayout_14")
        self.horizontalLayout_13 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_13.setObjectName("horizontalLayout_13")
        self.convert = QtWidgets.QPushButton(self.centralwidget)
        self.convert.setStyleSheet("QPushButton{\n"
"    background-color: #B5FBDD;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(224, 0, 0);\n"
"    border-style: inset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(252, 252, 252)\n"
"}")
        self.convert.setObjectName("convert")
        self.horizontalLayout_13.addWidget(self.convert)
        self.format_button = QtWidgets.QPushButton(self.centralwidget)
        self.format_button.setStyleSheet("QPushButton{\n"
"    background-color: #B5FBDD;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(224, 0, 0);\n"
"    border-style: inset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(252, 252, 252)\n"
"}")
        self.format_button.setObjectName("format_button")
        self.horizontalLayout_13.addWidget(self.format_button)
        self.visualize = QtWidgets.QPushButton(self.centralwidget)
        self.visualize.setStyleSheet("QPushButton{\n"
"    background-color: #B5FBDD;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(224, 0, 0);\n"
"    border-style: inset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(252, 252, 252)\n"
"}")
        self.visualize.setObjectName("visualize")
        self.horizontalLayout_13.addWidget(self.visualize)
        self.verticalLayout_14.addLayout(self.horizontalLayout_13)
        self.horizontalLayout_11 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_11.setObjectName("horizontalLayout_11")
        self.compress_xml = QtWidgets.QPushButton(self.centralwidget)
        self.compress_xml.setStyleSheet("QPushButton{\n"
"    background-color: #B5FBDD;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(224, 0, 0);\n"
"    border-style: inset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(252, 252, 252)\n"
"}")
        self.compress_xml.setObjectName("compress_xml")
        self.horizontalLayout_11.addWidget(self.compress_xml)
        self.comp_json = QtWidgets.QPushButton(self.centralwidget)
        self.comp_json.setStyleSheet("QPushButton{\n"
"    background-color: #B5FBDD;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(224, 0, 0);\n"
"    border-style: inset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(252, 252, 252)\n"
"}")
        self.comp_json.setObjectName("comp_json")
        self.horizontalLayout_11.addWidget(self.comp_json)
        self.Decomp_xml = QtWidgets.QPushButton(self.centralwidget)
        self.Decomp_xml.setEnabled(False)
        self.Decomp_xml.setStyleSheet("QPushButton{\n"
"    background-color: #B5FBDD;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(224, 0, 0);\n"
"    border-style: inset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(252, 252, 252)\n"
"}")
        self.Decomp_xml.setObjectName("Decomp_xml")
        self.horizontalLayout_11.addWidget(self.Decomp_xml)
        self.Decomp_json = QtWidgets.QPushButton(self.centralwidget)
        self.Decomp_json.setEnabled(False)
        self.Decomp_json.setStyleSheet("QPushButton{\n"
"    background-color: #B5FBDD;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(224, 0, 0);\n"
"    border-style: inset;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color:rgb(252, 252, 252)\n"
"}")
        self.Decomp_json.setObjectName("Decomp_json")
        self.horizontalLayout_11.addWidget(self.Decomp_json)
        self.verticalLayout_14.addLayout(self.horizontalLayout_11)
        self.horizontalLayout_12.addLayout(self.verticalLayout_14)
        self.verticalLayout_2.addLayout(self.horizontalLayout_12)
        self.verticalLayout_2.setStretch(0, 5)
        self.verticalLayout_2.setStretch(1, 1)
        self.verticalLayout.addLayout(self.verticalLayout_2)
        XML_Editor.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(XML_Editor)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 871, 22))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        self.menuAbout = QtWidgets.QMenu(self.menubar)
        self.menuAbout.setObjectName("menuAbout")
        XML_Editor.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(XML_Editor)
        self.statusbar.setObjectName("statusbar")
        XML_Editor.setStatusBar(self.statusbar)
        self.actionOpen = QtWidgets.QAction(XML_Editor)
        self.actionOpen.setObjectName("actionOpen")
        self.actionSave = QtWidgets.QAction(XML_Editor)
        self.actionSave.setObjectName("actionSave")
        self.actionSave_as = QtWidgets.QAction(XML_Editor)
        self.actionSave_as.setObjectName("actionSave_as")
        self.actionGithub = QtWidgets.QAction(XML_Editor)
        self.actionGithub.setObjectName("actionGithub")
        self.menuFile.addAction(self.actionOpen)
        self.menuFile.addSeparator()
        self.menuFile.addAction(self.actionSave_as)
        self.menuAbout.addAction(self.actionGithub)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuAbout.menuAction())

        self.retranslateUi(XML_Editor)
        QtCore.QMetaObject.connectSlotsByName(XML_Editor)

    def retranslateUi(self, XML_Editor):
        _translate = QtCore.QCoreApplication.translate
        XML_Editor.setWindowTitle(_translate("XML_Editor", "XML_Editor"))
        self.label_2.setText(_translate("XML_Editor", "Input"))
        self.label.setText(_translate("XML_Editor", "Output"))
        self.convert.setText(_translate("XML_Editor", "XML to JSON"))
        self.format_button.setText(_translate("XML_Editor", "Format"))
        self.visualize.setText(_translate("XML_Editor", "Visualize"))
        self.compress_xml.setText(_translate("XML_Editor", "Compress XML"))
        self.comp_json.setText(_translate("XML_Editor", "Compress JSON"))
        self.Decomp_xml.setText(_translate("XML_Editor", "Decompress XML"))
        self.Decomp_json.setText(_translate("XML_Editor", "Decompress JSON"))
        self.menuFile.setTitle(_translate("XML_Editor", "File"))
        self.menuAbout.setTitle(_translate("XML_Editor", "About"))
        self.actionOpen.setText(_translate("XML_Editor", "Open File"))
        self.actionOpen.setShortcut(_translate("XML_Editor", "Ctrl+O"))
        self.actionSave.setText(_translate("XML_Editor", "Save"))
        self.actionSave_as.setText(_translate("XML_Editor", "Save as"))
        self.actionSave_as.setShortcut(_translate("XML_Editor", "Ctrl+S"))
        self.actionGithub.setText(_translate("XML_Editor", "Github"))
import Resourses_rc
