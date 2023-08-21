#!/usr/bin/python3

def complex_delete(a_dictionary, value):
    keys_to_delete = [key for key, val in a_dictionary.items() if val == value]
    new_dict = {key: val for key, val in a_dictionary.items() if key not in keys_to_delete}
    return new_dict
