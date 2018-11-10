import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from mpl_toolkits.axes_grid1 import make_axes_locatable
import sys


def get_tuple_from_file(filename):
    file = open(filename, "r")
    filename_params = filename.split("_")
    v = filename_params[3]
    L = filename_params[4].split(".")[0]
    distance = file.readline()
    file.close()
    return (float(v), float(L)*1E3, float(distance)*np.sign(float(distance)), False if float(distance) < 0 else True)


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
usefullness = []
for tuple in tuples:
    if(tuple[0] != current_v):
        if(current_v != None):
            distances.append(temp_array_1)
            usefullness.append(temp_array_2)
            adding_altitudes = False
        current_v = tuple[0]
        velocities.append(tuple[0])
        temp_array_1 = []
        temp_array_2 = []
        temp_array_1.append(tuple[2])
        temp_array_2.append(tuple[3])
    else:
        temp_array_1.append(tuple[2])
        temp_array_2.append(tuple[3])
    if adding_altitudes:
        altitudes.append(tuple[1])
distances.append(temp_array_1)
usefullness.append(temp_array_2)

ax = plt.subplot(111)
im = ax.imshow(distances)

# create an axes on the right side of ax. The width of cax will be 5%
# of ax and the padding between cax and ax will be fixed at 0.05 inch.
divider = make_axes_locatable(ax)
cax = divider.append_axes("right", size="5%", pad=0.1)

plt.colorbar(im, cax=cax)

ax.set_xticks(np.arange(len(distances)))
ax.set_yticks(np.arange(len(velocities)))

ax.set_xticklabels(altitudes)
ax.set_yticklabels(velocities)

plt.setp(ax.get_xticklabels(), rotation=45, ha="right",
         rotation_mode="anchor")

for col in range(len(velocities)):
    for fil in range(len(altitudes)):
        text = ax.text(fil, col, "OK" if usefullness[col][fil] else "",
                       ha="center", va="center", color="w")

ax.set_title("Distancia a Júpiter en función de $V_0$ y $L$", y=1.08, size=20)
ax.text(x=4, y=13, s="$L$ [km]", size=20)
ax.text(x=-2, y=4, s="$V_0$ [km/s]", size=20, rotation=90,
        ha="right", rotation_mode="anchor")
plt.tight_layout()

plt.show()
