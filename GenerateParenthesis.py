def bracket(n, asf, open, close):
    if n == 0:
        if open == close:
            print(asf)
        return
    if open > close:
        bracket(n - 1, asf + ")", open, close + 1)
    # if close
    bracket(n - 1, asf + "(", open + 1, close)


n = int(input())
bracket(2 * n, "", 0, 0)
