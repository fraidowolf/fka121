# plot h(t)
# Created by Martin Gren 2014-10-25.

# imports
import matplotlib.pyplot as plt
import numpy as np

def plot_data(filename):

    # import data
    data = np.loadtxt(filename)


    # plot
    plt.plot(data[:,0], data[:,1],'-')

    # labels
    plt.xlabel('t / [arb. unit]', fontsize=12)
    plt.ylabel('h(t) / [arb. unit]', fontsize=12)

    # set tick fontsize
    plt.yticks(fontsize=12)
    plt.xticks(fontsize=12)

if __name__=='__main__':
 
    # size of figure
    plt.figure(figsize=(8,4.5))  
    plot_data('function_f2.dat')
    plot_data('function_f1.dat')
    plot_data('function_f1_phi.dat')
    plt.legend(['f=2','f=1','phi=pi/2'])
    # save the plot
    plt.savefig('h_t.pdf')

    # display the plot
    plt.show()


