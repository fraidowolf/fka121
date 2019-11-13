import matplotlib.pyplot as plt
import csv
import numpy as np
from itertools import chain

def E1_1():
    data1 = np.loadtxt('cos_func1.csv')
    data2 = np.loadtxt('cos_func2.csv')
    data3 = np.loadtxt('cos_func3.csv')
    plt.figure()
    plt.plot(data1[:,0],data1[:,1])
    plt.plot(data2[:,0],data2[:,1])
    plt.plot(data3[:,0],data3[:,1])
    plt.show()

def E1_2(filename,c):
    data_FT = np.loadtxt(filename)
    N = data_FT.shape[0]+1
    dt = data_FT[1,0]-data_FT[0,0]
    df = 1/(N*dt)
    f = [i*df for i in chain(range(1,N//2+1),range(-N//2+1,0))] #1,N+1)] #N//2,N//2-1)]
    print(N/2)

    plt.plot(f,data_FT[:,2],color=c)


if __name__ == '__main__':
    plt.figure()
    E1_2("with_FT_N260.csv",'red')
    E1_2("with_FT_N258.csv",'blue')
    E1_2("with_FT_N250.csv",'green')
    E1_2("with_FT_N256.csv",'k')
    plt.show()
    E1_1()
