from xmlrpc.server import SimpleXMLRPCServer

def addition(a,b):
    return (a+b)

def subraction(a,b):
    return (a-b)

def multiplication(a,b):
    return (a*b)

def division(a,b):
    return (a/b)

def maximum(a,b):
    if(a>b):
        return a
    else:
        return b

def minimum(a,b):
    if(a>b):
        return b
    else:
        return a

def square(n):
    return (n*n)

def cube(n):
    return (n*n*n)

def factorial(n):
    if(n<0):
        return -1
    fact=1
    for i in range(1,n+1):
        fact=fact*i
    return fact

port=8000
server=SimpleXMLRPCServer(('localhost',8000),logRequests=False)

server.register_function(addition,'addition_rpc')
server.register_function(subraction,'subraction_rpc')
server.register_function(multiplication,'multiplication_rpc')
server.register_function(division,'division_rpc')
server.register_function(maximum,'maximum_rpc')
server.register_function(minimum,'minimum_rpc')
server.register_function(square,'square_rpc')
server.register_function(cube,'cube_rpc')
server.register_function(factorial,'factorial_rpc')

try:
    print('Server started at Port:',port)
    server.serve_forever()

except:
    print('Exit')

'''
VVV Important Note:-
server.register_function(<functionname without inverted commas>,'<newfunctionname in inverted commas>')
'''

'''
/usr/local/bin/python3 "/Users/aryangalande/Desktop/LP1/C2) RPC/server.py"

Server started at Port: 8000
'''

