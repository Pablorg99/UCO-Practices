from model.attribute import Attribute
from rules.equivalence_rule import EquivalenceRule
from rules.in_range_rule import InRangeRule


class Fruit:
    def __init__(self, attributes):
        self.objects = [""]
        color = Attribute("color", attributes[0], EquivalenceRule)
        weight = Attribute("weight", attributes[1], InRangeRule)
        diameter = Attribute("diameter", attributes[2], InRangeRule)
        self.attributes = [color, weight, diameter]
