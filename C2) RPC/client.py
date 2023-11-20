import xmlrpc.client

proxy=xmlrpc.client.ServerProxy('http://localhost:8000/')

while(True):
    print('--------------------------------------------')
    print('RPC')
    print('1) Addition of 2 Numbers')
    print('2) Subraction of 2 Numbers')
    print('3) Multiplication of 2 Numbers')
    print('4) Division of 2 Numbers')
    print('5) Maximum of 2 Numbers')
    print('6) Minimum of 2 Numbers')
    print('7) Square of a Number')
    print('8) Cube of a Number')
    print('9) Factorial of a Number')
    print('10) Exit')
    print('Enter Choice: ')
    ch=int(input())
    print('--------------------------------------------')

    if(ch==1):
        print('Enter 2 Numbers: ')
        a=int(input())
        b=int(input())
        ans=str(proxy.addition_rpc(a,b))
        print('Addition of ',a,' and ',b,' is ',ans)

    elif(ch==2):
        print('Enter 2 Numbers: ')
        a=int(input())
        b=int(input())
        ans=str(proxy.subraction_rpc(a,b))
        print('Subraction of ',a,' and ',b,' is ',ans)

    elif(ch==3):
        print('Enter 2 Numbers: ')
        a=int(input())
        b=int(input())
        ans=str(proxy.multiplication_rpc(a,b))
        print('Multiplication of ',a,' and ',b,' is ',ans)

    elif(ch==4):
        print('Enter 2 Numbers: ')
        a=int(input())
        b=int(input())
        ans=str(proxy.division_rpc(a,b))
        print('Division of ',a,' and ',b,' is ',ans)

    elif(ch==5):
        print('Enter 2 Numbers: ')
        a=int(input())
        b=int(input())
        ans=str(proxy.maximum_rpc(a,b))
        print('Maximum of ',a,' and ',b,' is ',ans)

    elif(ch==6):
        print('Enter 2 Numbers: ')
        a=int(input())
        b=int(input())
        ans=str(proxy.minimum_rpc(a,b))
        print('Minimum of ',a,' and ',b,' is ',ans)

    elif(ch==7):
        print('Enter Number: ')
        a=int(input())
        ans=str(proxy.square_rpc(a))
        print('Square of ',a,' is ',ans)
        
    elif(ch==8):
        print('Enter Number: ')
        a=int(input())
        ans=str(proxy.cube_rpc(a))
        print('Cube of ',a,' is ',ans)

    elif(ch==9):
        print('Enter Number: ')
        a=int(input())
        ans=str(proxy.factorial_rpc(a))
        print('Factorial of ',a,' is ',ans)

    elif(ch==10):
        print('Exiting Program !!')
        break

    else:
        print('Invalid Choice !!')

'''
/usr/local/bin/python3 "/Users/aryangalande/Desktop/LP1/C2) RPC/client.py"

--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
1
--------------------------------------------
Enter 2 Numbers: 
4
2
Addition of  4  and  2  is  6
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
2
--------------------------------------------
Enter 2 Numbers: 
4
2
Subraction of  4  and  2  is  2
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
3
--------------------------------------------
Enter 2 Numbers: 
4
2
Multiplication of  4  and  2  is  8
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
4
--------------------------------------------
Enter 2 Numbers: 
4
2
Division of  4  and  2  is  2.0
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
5
--------------------------------------------
Enter 2 Numbers: 
4
2
Maximum of  4  and  2  is  4
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
6
--------------------------------------------
Enter 2 Numbers: 
4
2
Minimum of  4  and  2  is  2
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
7
--------------------------------------------
Enter Number: 
4
Square of  4  is  16
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
8
--------------------------------------------
Enter Number: 
4
Cube of  4  is  64
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
9
--------------------------------------------
Enter Number: 
4
Factorial of  4  is  24
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
11
--------------------------------------------
Invalid Choice !!
--------------------------------------------
RPC
1) Addition of 2 Numbers
2) Subraction of 2 Numbers
3) Multiplication of 2 Numbers
4) Division of 2 Numbers
5) Maximum of 2 Numbers
6) Minimum of 2 Numbers
7) Square of a Number
8) Cube of a Number
9) Factorial of a Number
10) Exit
Enter Choice: 
10
--------------------------------------------
Exiting Program !!
'''
        
    

