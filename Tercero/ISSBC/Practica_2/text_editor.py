#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from PyQt4 import QtGui, QtCore


class TextEditorWindow(QtGui.QMainWindow):

    def __init__(self):
        QtGui.QMainWindow.__init__(self)
        self.addTextInputWidget()
        self.createActions()
        self.addMenuBarSections()
        self.addToolBarItems()
        self.setWindowStyle()

    def addTextInputWidget(self):
        self.textInputWidget = QtGui.QTextEdit(self)
        self.setCentralWidget(self.textInputWidget)

    def createActions(self):
        self.createNewFileAction()
        self.createOpenFileAction()
        self.createSaveFileAction()
        self.createBoldTextAction()
        self.createItalicTextAction()
        self.createUnderlineTextAction()

    def addMenuBarSections(self):
        self.addFileSectionToMenuBar()
        self.addStyleSectionToMenuBar()

    def addFileSectionToMenuBar(self):
        menuBar = self.menuBar()
        fileMenuSection = menuBar.addMenu('&File')
        fileMenuSection.addAction(self.newFileAction)
        fileMenuSection.addAction(self.openFileAction)
        fileMenuSection.addAction(self.saveFileAction)

    def addStyleSectionToMenuBar(self):
        menuBar = self.menuBar()
        styleMenuSection = menuBar.addMenu('&Style')
        styleMenuSection.addAction(self.boldTextAction)
        styleMenuSection.addAction(self.italicTextAction)
        styleMenuSection.addAction(self.underlineTextAction)

    def addToolBarItems(self):
        self.mainToolBar = self.addToolBar('Main Tool Bar')
        self.mainToolBar.addAction(self.newFileAction)
        self.mainToolBar.addAction(self.openFileAction)
        self.mainToolBar.addAction(self.saveFileAction)
        self.mainToolBar.addSeparator()
        self.mainToolBar.addAction(self.boldTextAction)
        self.mainToolBar.addAction(self.italicTextAction)
        self.mainToolBar.addAction(self.underlineTextAction)

    def setWindowStyle(self):
        self.setGeometry(300, 300, 900, 600)
        self.setWindowTitle("Text Editor")

    def createNewFileAction(self):
        self.newFileAction = QtGui.QAction('New File', self)
        self.newFileAction.setIcon(QtGui.QIcon('icons/new_file.png'))
        self.newFileAction.setShortcut('Ctrl+N')
        self.newFileAction.triggered.connect(self.newFile)

    def newFile(self):
        self.textInputWidget.clear()

    def createOpenFileAction(self):
        self.openFileAction = QtGui.QAction('Open File', self)
        self.openFileAction.setIcon(QtGui.QIcon('icons/open_file.png'))
        self.openFileAction.setShortcut('Ctrl+O')
        self.openFileAction.triggered.connect(self.openFile)

    def openFile(self):
        filename = QtGui.QFileDialog.getOpenFileName(self, 'Open File')
        file = open(filename, 'r')
        filedata = file.read()
        self.textInputWidget.setText(filedata)
        file.close()

    def createSaveFileAction(self):
        self.saveFileAction = QtGui.QAction('Save File', self)
        self.saveFileAction.setIcon(QtGui.QIcon('icons/save_file.png'))
        self.saveFileAction.setShortcut('Ctrl+S')
        self.saveFileAction.triggered.connect(self.saveFile)

    def saveFile(self):
        filename = QtGui.QFileDialog.getSaveFileName(self, 'Save File')
        file = open(filename, 'w')
        filedata = self.textInputWidget.toPlainText()
        file.write(filedata)
        file.close()

    def createBoldTextAction(self):
        self.boldTextAction = QtGui.QAction('Bold', self)
        self.boldTextAction.setIcon(QtGui.QIcon('icons/bold_text.png'))
        self.boldTextAction.setShortcut('Ctrl+B')
        self.boldTextAction.triggered.connect(self.boldText)

    def boldText(self):
        if self.textInputWidget.fontWeight() == QtGui.QFont.Bold:
            self.textInputWidget.setFontWeight(QtGui.QFont.Normal)

        else:
            self.textInputWidget.setFontWeight(QtGui.QFont.Bold)

    def createItalicTextAction(self):
        self.italicTextAction = QtGui.QAction('Italic', self)
        self.italicTextAction.setIcon(QtGui.QIcon('icons/italic_text.png'))
        self.italicTextAction.setShortcut('Ctrl+I')
        self.italicTextAction.triggered.connect(self.italicText)

    def italicText(self):
        currentState = self.textInputWidget.fontItalic()
        self.textInputWidget.setFontItalic(not currentState)

    def createUnderlineTextAction(self):
        self.underlineTextAction = QtGui.QAction('Underline', self)
        self.underlineTextAction.setIcon(
            QtGui.QIcon('icons/underline_text.png'))
        self.underlineTextAction.setShortcut('Ctrl+U')
        self.underlineTextAction.triggered.connect(self.underlineText)

    def underlineText(self):
        currentState = self.textInputWidget.fontUnderline()
        self.textInputWidget.setFontUnderline(not currentState)


def main():
    app = QtGui.QApplication(sys.argv)
    textEditorWindow = TextEditorWindow()
    textEditorWindow.show()

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
