# random number generator - least congruential method
'''
x0 = seed element
a = multiplier
c = increment
m = module
For a = 1, it will be additive congruence method.
For c = 0, it will be the multiplicative congruence method. 
c !=0 , it will be mixed lcm
ri = x1/m
'''
def generateRan(x0, a, c, m):

    rand = []
    randr = []

    x1 = (a*x0 + c)%m
    rand.append(x1)
    randr.append(x1/m)
    i = 2
    while(x1!= x0):
        x1 = (a*x1 + c)%m
        print('(X{} = x{}*a + c)%m'.format(i, i-1))
        print('X{} = {}'.format(i, x1))
        rand.append(x1)
        randr.append(x1/m)
        i+=1

    return rand, randr

x0 = int(input('Enter X0: '))
a = int(input('Enter a: '))
c = int(input('Enter c: '))
m = int(input('Enter m: '))
elems,random = generateRan(x0,a,c,m)
print('Random numbers: ', elems)
print('Random number in decimals: ',random)









