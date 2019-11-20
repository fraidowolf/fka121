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

if __name__=='__main__':
    
    # size of figure
    plt.figure(figsize=(8,6))


    plot_data('powerspectrum_f2.dat')
    plot_data('powerspectrum_f1.dat')
    plot_data('powerspectrum_phi.dat')
    plt.legend(['f=2','f=1','phi=pi/2'])
    # save and display the plot
    plt.savefig('powerspectrum.pdf')
    plt.show()


