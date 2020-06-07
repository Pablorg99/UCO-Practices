from PyQt4 import QtCore, QtGui

from controller.domain import DomainController
from controller.classification import ClassificationController
from model.domain_list import DOMAIN_LIST


class MainWindow(QtGui.QWidget):
    def __init__(self, domain):
        super(MainWindow, self).__init__()
        self.__domain = domain
        self.__classification_controller = None
        self.__domain_controller = DomainController(self.__domain)
        attrs_number = self.__domain_controller.get_domain_attributes()
        self.__model_attributes = [""] * len(attrs_number)
        self.__layout = self.__set_layout()
        self.__update_grid_elements()
        self.setGeometry(500, 300, 900, 500)
        self.setWindowTitle("Classification App")
        self.show()

    def __set_layout(self):
        grid = QtGui.QGridLayout()
        grid.setContentsMargins(40, 30, 40, 30)
        return grid

    def __update_grid_elements(self):

        domain_selector = self.__create_combo_box()
        input_data_table = self.__create_table_for()
        candidate_objects_information = self.__create_objects_info_text()
        classify_button = self.__create_classify_button()
        matching_objects = self.__create_matching_objects_text()

        horizontal_box = QtGui.QHBoxLayout()
        horizontal_box.addWidget(domain_selector)
        horizontal_box.addWidget(classify_button)
        horizontal_box.addWidget(QtGui.QLabel('Matching Objects:'))
        horizontal_box.addWidget(matching_objects)

        self.__layout.addWidget(QtGui.QLabel('Object Input Form'), 0, 0)
        self.__layout.addWidget(QtGui.QLabel('Candidate Objects Info'), 0, 1)
        self.__layout.addWidget(input_data_table, 1, 0)
        self.__layout.addWidget(candidate_objects_information, 1, 1)
        self.__layout.addLayout(horizontal_box, 2, 0, 1, 2)

        self.setLayout(self.__layout)

    def __create_table_for(self):
        attributes = self.__domain_controller.get_domain_attributes()
        input_data_table = QtGui.QTableWidget(len(attributes), 2)
        input_data_table.setHorizontalHeaderLabels(['Attribute', 'Value'])
        input_data_table.setColumnWidth(0, 196)
        input_data_table.setColumnWidth(1, 195)
        for i in range(0, len(attributes)):
            attribute_cell = QtGui.QTableWidgetItem(attributes[i])
            attribute_cell.setFlags(self.__get_uneditable_cell_flags())
            value_cell = QtGui.QLineEdit()
            value_cell.row = i
            value_cell.setText(self.__model_attributes[i])
            value_cell.editingFinished.connect(self.__update_attribute_value)
            input_data_table.setItem(i, 0, attribute_cell)
            input_data_table.setCellWidget(i, 1, value_cell)
        return input_data_table

    def __get_uneditable_cell_flags(self):
        return QtCore.Qt.ItemIsUserCheckable | QtCore.Qt.ItemIsEnabled

    def __update_attribute_value(self):
        value_cell = self.sender()
        index = value_cell.row
        self.__model_attributes[index] = str(value_cell.text())

    def __create_objects_info_text(self):
        information = self.__domain_controller.get_objects_information()
        object_info_widget = QtGui.QPlainTextEdit(information)
        object_info_widget.setReadOnly(True)
        return object_info_widget

    def __create_combo_box(self):
        combo_box = QtGui.QComboBox()
        combo_box.addItem(self.__domain)
        for domain in DOMAIN_LIST:
            if domain != self.__domain:
                combo_box.addItem(domain)
        combo_box.currentIndexChanged.connect(self.__update_domain)
        return combo_box

    def __update_domain(self):
        combo_box = self.sender()
        self.__domain = str(combo_box.currentText())
        self.__domain_controller = DomainController(self.__domain)
        attrs_number = self.__domain_controller.get_domain_attributes()
        self.__model_attributes = [""] * len(attrs_number)
        self.__update_grid_elements()

    def __create_classify_button(self):
        classify_button = QtGui.QPushButton("Classify")
        classify_button.clicked.connect(self.__classify)
        return classify_button

    def __classify(self):
        model = self.__domain_controller.create_model_with(
            self.__model_attributes)
        objects = self.__domain_controller.get_domain_objects()
        self.__classification_controller = ClassificationController(
            self.__domain, model, objects)
        self.__update_grid_elements()

    def __create_matching_objects_text(self):
        if self.__classification_controller is None:
            empty_widget = QtGui.QLineEdit("")
            empty_widget.setReadOnly(True)
            return empty_widget
        matching_objects = self.__classification_controller.get_matching_objects()
        matching_objects_widget = QtGui.QLineEdit(str(matching_objects))
        matching_objects_widget.setReadOnly(True)
        return matching_objects_widget
