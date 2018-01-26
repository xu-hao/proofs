import itertools as it

def is_solution(perm):
    for (i1, i2) in it.combinations(range(len(perm)), 2):
        if abs(i1 - i2) == abs(perm[i1] - perm[i2]):
            return False

    return True

        # print('i1: {}, i2: {}'.format(i1, i2))
        # print('perm(i1): {}, perm(i2): {}'.format(perm[i1], perm[i2]))

for perm in it.permutations(range(4)):
    if is_solution(perm):
        print('solution: {}'.format(perm))
        exit()

    # print('entering solution space perm: {}'.format(perm))
    # is_solution(perm)
