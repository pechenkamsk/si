# -*- coding: utf-8 -*-
"""
Created on Fri May 21 17:28:54 2021

@author: nikra
"""

name=input("fail's name: ")
f=open(name, "r")
b=float("-inf")
a=float("-inf")
c=0
i=0
k=0
t=0
for s in f:
    for s1 in s.split(" "):
        for s2 in s1.split('\n'):
            for s3 in s2.split("\t"):
                for s4 in s3.split(","):
                    if (s4!=""):
                        if (k>0):
                            k=k-1
                            print("if a and c",a,c)
                            if (c>=a):
                                i=i+1
                                print("if i:",i)
                        t=t+1
                        print("шаг номер:",t)
                        c=b
                        b=a
                        print("b:",b)
                        print("c:",c)
                        a=float(s4)
                        print("a:",a)
                        if  (k<1):
                            if (a<=b):
                                i=i+1
                                print("i:",i)
                                k=k+1
                                print("k:",k)
                       
                        
                 
                            
                        
if (i>1):
    print("нельзя")
else:
    print("можно")
    
    