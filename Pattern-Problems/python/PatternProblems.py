# -*- coding: utf-8 -*-
"""
Created on Sun Oct 29 19:19:48 2017
Pattern-Problems(Python)
@forked from:thedeepanshujain
@author: Vasudev
"""
def pattern1(n):
    for i in range(n):
        for j in range(i+1):
            print('1',end=' ')
        print()
    return

def pattern2(n):
    val=1
    for i in range(n):
        for j in range(i+1):
            print(val,end=' ')
            val=val+1
        print()
    return

def pattern3(n):
    for i in range(n):
        val=i+1
        for j in range(i+1):
            print(val,end=' ')
            val=val+1
        print()
    return

def pattern4(n):
    i=n
    while i>=1:
        for j in range(i):
            print('1',end=' ')
        print()
        i=i-1
    return
    
def pattern5(n):
    i=n
    while i>=1:
        for j in range(1,i+1):
            print(j,end=' ')
        print()
        i=i-1
    return

def pattern6(n):
    for i in range(n):
        space=n-(i+1)
        while space>0:
            print(' ',end=' ')
            space=space-1
        for j in range(i+1):
            print('1',end=' ')
        print()
    return

def pattern7(n):
    val=1
    for i in range(n):
        space=n-(i+1)
        while space>0:
            print(' ',end=' ')
            space=space-1
        for j in range(i+1):
            print(val,end=' ')
            val=val+1
        print()
    return

def pattern8(n):
    for i in range(n):
        space=n-(i+1)
        while space>0:
            print(' ',end='')
            space=space-1
        for j in range(i+1):
            print(i+j+1,end='')
        print()
    return

def pattern9(n):
    for i in range(n):
        for space in range (1,i+1):
            print(' ',end=' ')
        for j in range(1,n-i+1):
            print('1',end=' ')
        print()
    return

def pattern10(n):
    for i in range(n):
        for space in range (1,i+1):
            print(' ',end=' ')
        for j in range(1,n-i+1):
            print(j,end=' ')
        print()
    return

def pattern11(n):
    for i in range(n):
        for j in range(i+1):
            var=(chr)(65+i)
            print(var,end=" ")
        print()
    return

def pattern12(n):
    i=n
    while i>=1:
        for j in range(i):
            if(i%2==0):
                print(1,end=' ')
            else:
                print(0,end=' ')
        print()
        i=i-1
    return

def pattern13(n):
    for i in range(n):
        for j in range(i+1):
            char=(chr)(n+64-i+j)
            print(char,end=" ")
        print()
    return

def pattern14(n):
    i=1
    val=1
    while(i<=n):
        j=1
        if(i%2==0):
            val=val+i
            evenRowVal=val-1
            while j<=i:
                print(evenRowVal,end=' ')
                evenRowVal=evenRowVal-1
                j=j+1
        else:
            while j<=i:
                print(val,end=' ')
                val=val+1
                j=j+1
        print()
        i=i+1
    return

def pattern15(n):
    i=1
    while i<=n:
        j=n
        val=65
        space=2
        while space<=i:
            print(" ",end=' ')
            space=space+1
        while j>=i:
            char=(chr)(val)
            print(char,end=' ')
            val=val+1
            j=j-1
        val=val-1
        j=n
        while j>=i:
            char=(chr)(val)
            print(char,end=' ')
            val=val-1
            j=j-1
        print()
        i=i+1
    return

def pattern16(n):
    i=1
    while i<=n:
        val=n-i+1
        j=1
        while j<=i:
            print (val,end=' ')
            val=val+1
            j=j+1
        while j<=n:
            print(n,end=' ')
            j=j+1
        print()
        i=i+1
    return


def pattern17(n):
    i=1
    while i<=n:
        space=n
        while space>i:
            print(" ",end=' ')
            space=space-1
        j=2
        val=i-1
        while j<=i:
            print(val,end=' ')
            val=val-1
            j=j+1
        print(val,end=' ')
        val=val+1
        j=2
        while j<=i:
            print(val,end=' ')
            val=val+1
            j=j+1
        print()
        i=i+1
    return
            
def pattern18(n):
    m=(int)(n/2)
    k=n-m
    i=1
    while i<=m:
        j=1
        while j<=i:
            print("*",end=' ')
            j=j+1
        print()
        i=i+1
    i=1
    while i<=k:
        j=k
        while j>=i:
            print("*",end=' ')
            j=j-1
        print()
        i=i+1
    return

def pattern19(n):
    m=(int)(n/2)+1
    k=n-m
    i=1
    while i<=m:
        space=m
        while space>i:
            print(" ",end=' ')
            space=space-1
        j=1
        while j<=2*i-1:
            print("*",end=' ')
            j=j+1
        print()
        i=i+1
    i=k
    while i>=1:
        space=k
        while space>=i:
            print(" ",end=' ')
            space=space-1
        j=1
        while j<=2*i-1:
            print("*",end=' ')
            j=j+1
        print()
        i=i-1
    return

def pattern20(n):
    m=(int)(n/2)+1
    k=n-m
    i=1
    while i<=m:
        space=m
        while space>i:
            print(" ",end=' ')
            space=space-1
        j=1
        while j<=2*i-1:
            print(j,end=' ')
            j=j+1
        print()
        i=i+1
    i=k
    while i>=1:
        space=k
        while space>=i:
            print(" ",end=' ')
            space=space-1
        j=1
        while j<=2*i-1:
            print(j,end=' ')
            j=j+1
        print()
        i=i-1
    return

def pattern21(n):
    i=1
    while i<=n:
        space=n
        while space>i:
            print(" ",end=' ')
            space=space-1
        j=1
        val=i
        while(j<=2*i-1):
            if j<i:
                print(val,end=' ')
                val=val+1
            elif j==i:
                print(val,end=' ')
                val=val-1
            elif j>i:
                print(val,end=' ')
                val=val-1
            j=j+1
        print()
        i=i+1
    return

def pattern22(n):
    m=(int)(n/2)+1
    k=n-m
    i=1
    while i<=m:
        space=2
        while space<=i:
            print(" ",end=' ')
            space=space+1
        j=1
        while(j<=i):
            print("*",end=' ')
            j=j+1
        print()
        i=i+1
    i=k
    while i>=1:
        space=k
        while space<=i:
            print(" ",end=' ')
            space=space+1
        j=1
        while j<=i:
            print("*",end=' ')
            j=j+1
        print()
        i=i-1
    return
def pattern23(n):
    i=1
    while i<=n:
        j=1
        while j<=i:
            if j==1 or j==i:
                print(1,end=' ')
            else:
                print(2,end=' ')
            j=j+1
        print()
        i=i+1
    return

def pattern24(n):
    print(1)
    i=2
    while i<=n:
        j=1
        while j<=i:
            if j==1 or j==i:
                print(i-1,end=' ')
            else:
                print(0,end=' ')
            j=j+1
        print()
        i=i+1
    return

def pattern25(n):
    i=1
    while i<=n:
        space=n
        while space>i:
            print(" ",end=' ')
            space=space-1
        j=1
        while j<=i:
            print("*",end=' ')
            j=j+1
        j=2
        while j<=i:
            print("*",end=' ')
            j=j+1
        print()
        i=i+1
    return

def pattern26(n):
    i=1
    while i<=n:
        space=n
        while space>i:
            print(" ",end=' ')
            space=space-1
        j=1
        val=i
        while j<=i:
            print(val,end=' ')
            val=val-1
            j=j+1
        j=2
        val=2
        while j<=i:
            print(val,end=' ')
            val=val+1
            j=j+1
        print()
        i=i+1
    return

def pattern27(n):
    i=1
    while i<=n:
        j=n
        val=n
        while j>i:
            print(val,end=' ')
            val=val-1
            j=j-1
        print("*",end=' ')
        j=1
        val=i-1
        while j<i:
            print(val,end=' ')
            val=val-1
            j=j+1
        print()
        i=i+1
    return

def pattern28(n):
    i=1
    while i<=n:
        j=1
        while j<=n:
            if j==i:
                print("*",end=' ')
            else:
                print("0",end=' ')
            j=j+1
        print("*",end=' ')
        j=n
        while j>=1:
            if(j==i):
                print("*",end=' ')
            else:
                print("0",end=' ')
            j=j-1
        print()
        i=i+1
    return

def pattern29(n):
    i=1
    while i<=n:
        val=1
        j=1
        while j<=i:
            print(val,end=' ')
            val=val+1
            j=j+1
        while j<=n:
            print("   ",end=' ')
            j=j+1
        j=1
        val=i
        while j<=i:
            print(val,end=' ')
            val=val-1
            j=j+1
        print()
        i=i+1
    return

def pattern31(n):
    i=1
    while i<=n-1:
        j=1
        while j<=n:
            if j==i:
                print(i,end=' ')
            else:
                print(" ",end=' ')
            j=j+1
        j=1
        while j<=n-1:
            if j==n-i:
                print(i,end=' ')
            else:
                print(" ",end=' ')
            j=j+1
        print()
        i=i+1
    j=1
    while j<=n-1:
        print(" ",end=' ')
        j=j+1
    print(n,end=' ')
    print()
    i=1
    while i<=n-1:
        j=1
        while j<=n:
            if j==n-i:
                print(j,end=' ')
            else:
                print(" ",end=' ')
            j=j+1
        j=1
        while j<=n-1:
            if j==i:
                print(n-i,end=' ')
            else:
                print(" ",end=' ')
            j=j+1
        print()
        i=i+1
    return

def pattern32(n):
    i=1
    val=1
    k=1
    while i<=n:
        j=1
        while j<=k:
            if(val==10):
                val=1
            print(val,end=' ')
            val=val+1
            j=j+1
        k=k*2
        print()
        i=i+1
    return

def pattern33(n):
    i=1
    while i<=n:
        j=1
        while j<=n+1:
            if j==i:
                print(i,end=' ')
            elif j<i:
                print(" ",end=' ')
            elif j>i:
                print("*",end=' ')
            j=j+1
        print()
        i=i+1
    i=1
    while i<=n-1:
        j=1
        while j<=n+1:
            if j==n-i:
                print(j,end=' ')
            elif j>n-i:
                print("*",end=' ')
            else:
                print(" ",end=' ')
            j=j+1
        print()
        i=i+1
    return
