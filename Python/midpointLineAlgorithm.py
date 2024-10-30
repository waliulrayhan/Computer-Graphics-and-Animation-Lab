import matplotlib.pyplot as plt

def Midpoint_Line(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    d = 2 * dy - dx
    incrE = 2 * dy
    incrNE = 2 * (dy - dx)

    points = [(x1, y1)]
    x = x1
    y = y1
    while x < x2:
        if d <= 0:
            d += incrE
            x += 1
        else:
            d += incrNE
            x += 1
            y += 1
        points.append((x, y))
    return points

def main():
    x1, y1 = map(int, input("Enter coordinates of the first point (x1 y1): ").split())
    x2, y2 = map(int, input("Enter coordinates of the second point (x2 y2): ").split())

    points = Midpoint_Line(x1, y1, x2, y2)

    print("Midpoint Line Drawing Algorithm:")
    print(f"({x1}, {y1}) -> ({x2}, {y2})")
    print("Points on the line:")
    for point in points:
        print(point)

    # Plotting the line
    x_values, y_values = zip(*points)
    plt.plot(x_values, y_values, marker='o')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('Midpoint Line Drawing Algorithm')
    plt.grid()
    plt.show()

if __name__ == "__main__":
    main()