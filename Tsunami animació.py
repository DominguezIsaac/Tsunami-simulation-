
import numpy as np
import matplotlib
# matplotlib.use("Agg") # useful for a webserver case where you don't want to ever visualize the result live.
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib.animation import FFMpegWriter, PillowWriter

g=9.8
h=100
u0=np.sqrt(g*h)
nu=0.967*10**(-6)


# Change to reflect your file location!
plt.rcParams['animation.ffmpeg_path'] = 'C:\\Users\\surfi\\Documents\\Programas\\ffmpeg-master-latest-win64-gpl\\bin\\ffmpeg.exe'


# Especifica la ruta del archivo de texto generado por el código en C
ruta_archivo = "C:\\Users\\surfi\\Desktop\\MN pr lliure\\Iteracio\\"

#ahora hay que coger las primeras 100 lineas del codigo i guardarlas en una tercera dimension de la matriz U que sera t=1, dentro de un bucle.

dimx=100
dimy=100
dimt=1000



metadata = dict(title='Tsunami eq Burgers 100m', artist='Isaac')
writer = FFMpegWriter(fps=50, metadata=metadata)

fig, ax = plt.subplots(subplot_kw=dict(projection='3d'), figsize=(16, 9), dpi=100)

x=np.linspace(-50,50,dimx)
y=np.linspace(-50,50,dimy)

X, Y = np.meshgrid(x, y)

    
with writer.saving(fig, "Video Tsunami Burgers 100 m.mp4", 100):
    for i in range(dimt):
        fitxer = ruta_archivo + f"Burgers_iteracio_{i}.txt"
        M = np.loadtxt(fitxer)
        
        
        ax.set_zlim(0, 30)
        ax.set_xlabel('x[m]')
        ax.set_ylabel('y[m]')
        ax.set_zlabel('v[m/s]')
        
        ax.plot_surface(X, Y, M, cmap='plasma', edgecolor='k')
        ax.get_proj = lambda: np.dot(Axes3D.get_proj(ax), np.diag([1, 1, 0.3, 1]))
        
        
        writer.grab_frame()
        plt.cla()