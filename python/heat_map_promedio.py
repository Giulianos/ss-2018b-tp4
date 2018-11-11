import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from mpl_toolkits.axes_grid1 import make_axes_locatable
import sys
from matplotlib.image import imread
from matplotlib.colors import LinearSegmentedColormap


def get_tuple_from_file(filename):
    file = open(filename, "r")
    filename_params = filename.split("_")
    v = filename_params[3]
    L = filename_params[4].split(".")[0]
    data_jupiter = file.readline()
    data_saturn = file.readline()
    data_jupiter = data_jupiter.split(";")
    data_saturn = data_saturn.split(";")
    file.close()
    average = float(data_saturn[0])
    return (float(v), float(L)*1E3, np.log10(average))


tuples = []

for filename in sys.argv:
    if filename == sys.argv[0]:
        is_script_file = False
        continue
    tuples.append(get_tuple_from_file(filename))

tuples.sort()

current_v = None
temp_array_1 = None
temp_array_2 = None
adding_altitudes = True
velocities = []
altitudes = []
distances = []
for tuple in tuples:
    if(tuple[0] != current_v):
        if(current_v != None):
            distances.append(temp_array_1)
            adding_altitudes = False
        current_v = tuple[0]
        velocities.append(tuple[0])
        temp_array_1 = []
        temp_array_1.append(tuple[2])
    else:
        temp_array_1.append(tuple[2])
    if adding_altitudes:
        altitudes.append(tuple[1])
distances.append(temp_array_1)

colormap_img = imread('python/colormap.png')
colors_from_img = colormap_img[:, 0, :]
my_cmap = LinearSegmentedColormap.from_list('my_cmap', colors_from_img, N=256)

ax = plt.subplot(111)
im = ax.imshow(distances, cmap=my_cmap, origin='lower')

# create an axes on the right side of ax. The width of cax will be 5%
# of ax and the padding between cax and ax will be fixed at 0.05 inch.
divider = make_axes_locatable(ax)
cax = divider.append_axes("right", size="5%", pad=0.1)

plt.colorbar(im, cax=cax)

ax.set_xticks(np.arange(len(altitudes)))
ax.set_yticks(np.arange(len(velocities)))


plt.setp(ax.get_xticklabels(), rotation=90, ha="right",
         rotation_mode="anchor")

ax.set_title("Distancia a Saturno en función de $V_0$ y $L$",
             y=1.08, size=20)
plt.tight_layout()

plt.show()
