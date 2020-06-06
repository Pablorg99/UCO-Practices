from model.attribute import Attribute
from rules.equivalence_rule import EquivalenceRule
from rules.in_range_rule import InRangeRule


class Fruit:
    def __init__(self, values=["", "", ""]):
        color = Attribute("color", values[0], EquivalenceRule)
        weight = Attribute("weight", values[1], InRangeRule)
        diameter = Attribute("diameter", values[2], InRangeRule)
        self.attributes = [color, weight, diameter]

    def get_attributes(self):
        attributes = []
        for attribute in self.attributes:
            attributes.append(attribute.name)
        return attributes
