import matplotlib.pyplot as plt
import csv
import numpy as np

def E1_1():
    data1 = np.loadtxt('cos_func1.csv')
    data2 = np.loadtxt('cos_func2.csv')
    data3 = np.loadtxt('cos_func3.csv')
    print(data1)
    plt.figure()
    plt.plot(data1[:,0],data1[:,1])
    plt.plot(data2[:,0],data2[:,1])
    plt.plot(data3[:,0],data3[:,1])
    plt.show()

def E1_2():
    data_FT = np.loadtxt('with_FT.csv')
    N = data_FT.shape[0]
    dt = data_FT[1,0]-data_FT[0,0]
    print(dt)
    print(N)
    df = 1/((N+1)*dt)
    print(df)
    f = [i*df for i in range(1,N+1)]

    plt.figure()
    plt.plot(f,data_FT[:,2])
    plt.show()


if __name__ == '__main__':
    E1_2()
    E1_1()
