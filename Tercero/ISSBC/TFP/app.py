import sys
from PyQt4 import QtGui

from views.main_window import MainWindow
from model.domain_list import DOMAIN_LIST

app = QtGui.QApplication(sys.argv)
main_window = MainWindow(DOMAIN_LIST[0])
sys.exit(app.exec_())
