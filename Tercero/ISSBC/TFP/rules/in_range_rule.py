class InRangeRule:
    @staticmethod
    def satisfied(value_to_check, correct_values):
        if correct_values[0] <= value_to_check <= correct_values[1]:
            return True
        return False
