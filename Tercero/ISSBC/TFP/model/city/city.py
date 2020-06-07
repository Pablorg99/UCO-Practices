from model.attribute import Attribute
from rules.equivalence_rule import EquivalenceRule
from rules.in_range_rule import InRangeRule


class City:
    def __init__(self, values=["", ""]):
        province = Attribute("province", values[0], EquivalenceRule)
        inhabitants = Attribute("inhabitants", values[1], InRangeRule)
        self.attributes = [province, inhabitants]

    def get_attributes(self):
        attributes = []
        for attribute in self.attributes:
            attributes.append(attribute.name)
        return attributes
