import sys
import matplotlib.pyplot as plt

inputs = []

for index in range(1, len(sys.argv), 2):
    input = {
        'filename': sys.argv[index],
        'label': sys.argv[index+1],
        'file': open(sys.argv[index], "r")
    }
    inputs.append(input)

for input in inputs:
    read = True
    input['positions'] = []
    input['times'] = []
    while read:
        # read particle quantity
        if input['file'].readline() == '':
            read = False
            continue
        # read comment line
        time = float(input['file'].readline())
        # read particle properties
        properties = input['file'].readline().split('\t')
        input['positions'].append(float(properties[0]))
        input['times'].append(time)

for input in inputs:
    plt.plot(input['times'], input['positions'], label=input['label'])

plt.legend()
plt.show()
