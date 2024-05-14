import matplotlib.pyplot as plt

def DDA_Line(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    steps = max(abs(dx), abs(dy))
    x_increment = dx / steps
    y_increment = dy / steps

    points = [(x1, y1)]
    x = x1
    y = y1
    for i in range(steps):
        x += x_increment
        y += y_increment
        points.append((round(x), round(y)))

    return points

def main():
    x1, y1 = map(int, input("Enter coordinates of the first point (x1 y1): ").split())
    x2, y2 = map(int, input("Enter coordinates of the second point (x2 y2): ").split())

    points = DDA_Line(x1, y1, x2, y2)

    print("DDA Line Drawing Algorithm:")
    print(f"({x1}, {y1}) -> ({x2}, {y2})")
    print("Points on the line:")
    for point in points:
        print(point)

    # Plotting the line
    x_values, y_values = zip(*points)
    plt.plot(x_values, y_values, marker='o')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.title('DDA Line Drawing Algorithm')
    plt.grid()
    plt.show()

if __name__ == "__main__":
    main()
