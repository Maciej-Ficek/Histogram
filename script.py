import matplotlib.pyplot as plt

def plot_data():
    x = range(101)
    y = []

    with open('result.txt', 'r') as file:
        for line in file:
            number = int(line.strip())
            y.append(number)

    plt.plot(x, y);
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Histogram')
    plt.grid(True)
    plt.show()

plot_data()
