class InRangeRule:
    @staticmethod
    def satisfied(value_to_check, correct_values):

        if (int(value_to_check) >= int(correct_values[0])) and (int(value_to_check) <= int(correct_values[1])):
            return True
        return False
