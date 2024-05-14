import matplotlib.pyplot as plt

def Midpoint_Circle(radius):
    x = 0
    y = radius
    d = 1 - radius
    deltaE = 3
    deltaSE = -2 * radius + 5

    points = []
    while x <= y:
        points.extend([(x, y), (-x, y), (x, -y), (-x, -y), (y, x), (-y, x), (y, -x), (-y, -x)])
        if d < 0:
            d += deltaE
            deltaE += 2
            deltaSE += 2
        else:
            d += deltaSE
            deltaE += 2
            deltaSE += 4
            y -= 1
        x += 1
    return points

def main():
    radius = int(input("Enter the radius of the circle: "))
    points = Midpoint_Circle(radius)

    print("Midpoint Circle Drawing Algorithm:")
    print("Radius:", radius)
    print("Points on the circle:")
    for point in points:
        print(point)

    # Plotting the circle
    x_values, y_values = zip(*points)
    plt.scatter(x_values, y_values)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Midpoint Circle Drawing Algorithm')
    plt.grid()
    plt.show()

if __name__ == "__main__":
    main()
