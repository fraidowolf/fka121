import matplotlib.pyplot as plt
import csv
import numpy as np

if __name__ == '__main__':
    random = np.loadtxt('u_random.csv')
    print(random)
    plt.figure()
    plt.hist(random)
    plt.show()
