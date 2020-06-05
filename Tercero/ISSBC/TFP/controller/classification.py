import importlib


class Classification:
    def __init__(self, name, attributes):
        self.__model = self.__get_model_from(name, attributes)
        self.__objects = self.__get_objects_from(name)

    def __get_model_from(self, name, attributes):
        module_name = "model." + name + "." + name
        module = importlib.import_module(module_name)
        class_name = name.capitalize()
        model = getattr(module, class_name)
        return model(attributes)

    def __get_objects_from(self, name):
        module_name = "model." + name + "." + name + "_objects"
        module = importlib.import_module(module_name)
        objects_name = name + "s"
        objects = getattr(module, objects_name)
        return objects

    def get_matching_objects(self):
        matching_objects = []
        for _key, _object in self.__objects.items():
            if self.__model_match_with(_object):
                matching_objects.append(_key)
        return matching_objects

    def __model_match_with(self, _object):
        for attribute in self.__model.attributes:
            object_attribute = _object[attribute.name]
            if not attribute.rule.satisfied(attribute.value, object_attribute):
                return False
        return True
