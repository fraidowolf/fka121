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


    plot_data('powerspectrum_f2.dat')
    plot_data('powerspectrum_f1.dat')
    plot_data('powerspectrum_f1_phi.dat')

    plot_data('powerspectrum_f2_N258.dat')
    plot_data('powerspectrum_f1_N258.dat')
    plot_data('powerspectrum_f1_phi_N258.dat')

    plot_data('powerspectrum_f2_N260.dat')
    plot_data('powerspectrum_f1_N260.dat')
    plot_data('powerspectrum_f1_phi_N260.dat')

    plt.legend(['N250: f=2','N250: f=1','N250: phi=pi/2',
                'N258: f=2','N258: f=1','N258: phi=pi/2',
                'N260: f=2','N260: f=1','N260: phi=pi/2'])
    # save and display the plot
    plt.savefig('powerspectrum.pdf')
    plt.show()

    # size of figure
    plt.figure(figsize=(8,6))


    plot_data('function_f2_N250.dat')
    plot_data('function_f1_N250.dat')
    plot_data('function_phi_N250.dat')

    plot_data('function_f2_N258.dat')
    plot_data('function_f1_N258.dat')
    plot_data('function_phi_N258.dat')

    plot_data('function_f2_N260.dat')
    plot_data('function_f1_N260.dat')
    plot_data('function_phi_N260.dat')

    plt.legend(['N250: f=2','N250: f=1','N250: phi=pi/2',
                'N258: f=2','N258: f=1','N258: phi=pi/2',
                'N260: f=2','N260: f=1','N260: phi=pi/2'])
    # save and display the plot
    plt.savefig('function.pdf')
    plt.show()


