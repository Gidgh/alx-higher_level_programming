def square_matrix_simple(matrix=[]):
    """
    Computes the square value of all integers in a matrix.
    
    Args:
        matrix (list[list[int]]): The input 2D matrix.
        
    Returns:
        list[list[int]]: A new matrix with squared values.
    """
    new_matrix = []
    for row in matrix:
        new_row = []
        for num in row:
            new_row.append(num ** 2)
        new_matrix.append(new_row)
    return new_matrix

