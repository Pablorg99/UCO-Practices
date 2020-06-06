import importlib
import pprint


class DomainController():
    def __init__(self, domain_name):
        self.__domain_name = domain_name

    def create_model_with(self, attributes):
        model = self.__get_model_instance()
        return model(attributes)

    def get_domain_objects(self):
        module_name = "model." + self.__domain_name + \
            "." + self.__domain_name + "_objects"
        module = importlib.import_module(module_name)
        objects_name = self.__domain_name + "s"
        objects = getattr(module, objects_name)
        return objects

    def get_objects_information(self):
        objects = self.get_domain_objects()
        objects_string = ""
        for _object, _dict in objects.items():
            objects_string += str(_object).capitalize() + ":\n"
            for key, value in _dict.items():
                objects_string += "      " + \
                    str(key).capitalize() + ": " + str(value) + "\n"
        return objects_string

    def get_domain_attributes(self):
        model = self.__get_model_instance()
        return model().get_attributes()

    def __get_model_instance(self):
        module_name = "model." + self.__domain_name + "." + self.__domain_name
        module = importlib.import_module(module_name)
        class_name = self.__domain_name.capitalize()
        return getattr(module, class_name)
