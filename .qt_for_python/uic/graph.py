# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/media/mustafa/E:/College/Data Structure & Algo/Project/XML-To-JSON/Forms/graph.ui'
#
# Created by: PyQt5 UI code generator 5.14.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Graph(object):
    def setupUi(self, Graph):
        Graph.setObjectName("Graph")
        Graph.resize(400, 300)
        self.horizontalLayout = QtWidgets.QHBoxLayout(Graph)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label = QtWidgets.QLabel(Graph)
        self.label.setText("")
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)

        self.retranslateUi(Graph)
        QtCore.QMetaObject.connectSlotsByName(Graph)

    def retranslateUi(self, Graph):
        _translate = QtCore.QCoreApplication.translate
        Graph.setWindowTitle(_translate("Graph", "Social Network"))
