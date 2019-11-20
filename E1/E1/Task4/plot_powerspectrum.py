# plot the powerspectrum
# Created by Martin Gren 2014-10-25.

# imports
import matplotlib.pylab as plt
import numpy as np

def plot_data(filename):
    # import data
    data = np.loadtxt(filename)

    # plot
    plt.plot(data[:,0], data[:,1],'-')

    # labels
    plt.xlabel('Frequency / [arb. unit]', fontsize=12)
    plt.ylabel('Power spectrum / [arb. unit]', fontsize=12)

    # set tick fontsize
    plt.yticks(fontsize=12)
    plt.xticks(fontsize=12)

def plot_h(filename):

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
    plt.figure(figsize=(8,6))


    plot_data('powerspectrum_dt0,1.dat')
    plot_data('powerspectrum_dt0,01.dat')
    plt.legend(['dt=0.1','dt=0.01'])
    # save and display the plot
    plt.savefig('powerspectrum.pdf')
    plt.show()

    # size of figure
    plt.figure(figsize=(8,6))
    plot_h('function_dt0,1.dat')
    plot_h('function_dt0,01.dat')
    plt.legend(['dt=0.1','dt=0.01'])
    # save and display the plot
    plt.savefig('function_dt5.pdf')
    plt.show()


