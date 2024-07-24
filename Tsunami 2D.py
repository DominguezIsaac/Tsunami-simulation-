# -*- coding: utf-8 -*-
"""
Created on Tue Jan 30 19:57:59 2024

@author: surfi
"""


from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import math
import scipy.stats as ss

import numpy as np

x0=200

# Especifica la ruta del archivo de texto generado por el código en C
ruta_archivo = "C:\\Users\\surfi\\Desktop\\MN pr lliure\\Iteracio2\\"

#ahora hay que coger las primeras 100 lineas del codigo i guardarlas en una tercera dimension de la matriz U que sera t=1, dentro de un bucle.

dimx=100
dimy=100
dimt=1000


for i in range(1):
    fitxer = ruta_archivo + f"Burgers_iteracio_{999}.txt"
    M = np.loadtxt(fitxer)
    
    fig, ax = plt.subplots(subplot_kw=dict(projection='3d'),figsize=(20,20))

    x=np.linspace(-100,100,dimx)
    y=np.linspace(-100,100,dimy)

    X, Y = np.meshgrid(x, y)

    ax.plot_surface(X, Y, M, cmap='plasma', edgecolor='k')
    
    ax.set_xlim(-100, 100)
    ax.set_ylim(-100, 100)
    ax.set_zlim(0, 30)
    
    ax.set_xlabel('x[m]')
    ax.set_ylabel('y[m]')
    ax.set_zlabel('h[m]')
    
    ax.get_proj = lambda: np.dot(Axes3D.get_proj(ax), np.diag([1, 1, 0.3, 1]))
    plt.show()
    #plt.savefig(f"C:\\Users\\surfi\\Desktop\\MN pr lliure\\Iteracio\\imatges\\imatge_{i}.png")
    #plt.close()
