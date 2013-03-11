def f(n):
    return reduce(lambda x, y: x*y, range(1, n+1))

print f(30);
