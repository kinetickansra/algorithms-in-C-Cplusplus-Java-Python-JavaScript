# General LCS method
def lcs(A1, A2, len1, len2):

    if len1 == 0 or len2 == 0:
        return 0

    elif A1[len1 - 1] == A2[len2 - 1]:
        return 1+lcs(A1, A2, len1 - 1, len2 - 1)

    else:
        return max(lcs(A1, A2, len1, len2 - 1), lcs(A1, A2, len1 - 1, len2))


A1 = "HELLOTHERE"
A2 = "HITHERE"
print("Length of LCS is ", lcs(A1, A2, len(A1), len(A2)))
