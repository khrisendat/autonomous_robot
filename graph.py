import serial
import time
import math
import numpy as np
import matplotlib.pyplot as plt
import sys
import pdb

def is_number(n):
    try:
        float(n)   # Type-casting the string to `float`.                                             
                   # If string is not a valid `float`,                                               
                   # it'll raise `ValueError` exception                                              
    except ValueError:
        return False
    return True

plt.ion() # interactive mode                                                                         

x_arr = []
y_arr = []
delim = ","

# we have to get x,y coor                                                                            
for line in sys.stdin:
    #returns cartesian coor                                                                          
    res = line.rstrip()
    arr = res.split(delim)

    if len(arr) == 2:
        radius, angle = arr

        print(1)
        if is_number(radius) and is_number(angle):
            angle = math.radians(float(angle))
            radius = float(radius)

            if radius >= 0:

                x_arr.append(math.cos(angle) * radius)
                y_arr.append(math.sin(angle) * radius)

                plt.scatter(x_arr,y_arr)
                plt.pause(0.01)
                plt.clf()


