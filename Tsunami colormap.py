import numpy as np
import matplotlib
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib.animation import FFMpegWriter, PillowWriter

plt.rcParams['animation.ffmpeg_path'] = 'C:\\Users\\surfi\\Documents\\Programas\\ffmpeg-master-latest-win64-gpl\\bin\\ffmpeg.exe'

g=9.8
h=100
u0=np.sqrt(g*h)
nu=0.967*10**(-6)

# Especifica la ruta del archivo de texto generado por el código en C
ruta_archivo = "C:\\Users\\surfi\\Desktop\\MN pr lliure\\Iteracio\\"

dimx=100
dimy=100
dimt=1000

metadata = dict(title='Tsunami colormap 100m', artist='Isaac')
writer = FFMpegWriter(fps=50, metadata=metadata)

fig,ax = plt.subplots(figsize=(16, 9), dpi=100)

im = ax.imshow(np.zeros((dimx, dimy)), cmap='plasma', extent=(-50, 50, -50, 50), vmin=0, vmax=30)

cbar = plt.colorbar(im)
cbar.set_label('v [m/s]')
ax.set_xlabel('x [m]')
ax.set_ylabel('y [m]')
    
    
with writer.saving(fig, "Video Tsunami colormap 100m.mp4", 100):
    for i in range(dimt):
        fitxer = ruta_archivo + f"Burgers_iteracio_{i}.txt"
        M = np.loadtxt(fitxer)
        
        im.set_array(M)
       
        writer.grab_frame()
