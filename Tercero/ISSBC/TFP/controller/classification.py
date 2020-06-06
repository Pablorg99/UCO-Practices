from controller.domain import DomainController


class ClassificationController:
    def __init__(self, domain_name, model, objects):
        self.__domain_controller = DomainController(domain_name)
        self.__model = model
        self.__objects = objects

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
