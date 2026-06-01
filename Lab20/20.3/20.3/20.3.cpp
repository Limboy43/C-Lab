class LazySquare {
private:
    double side;
    double area;
    bool side_changed;

public:
    LazySquare(double s) {
        side = s;
        area = s * s;
        side_changed = false;
    }

    void set_side(double s) {
        if (s >= 0) {
            side = s;
            side_changed = true;
        }
    }

    double get_area() {
        if (side_changed) {
            area = side * side;
            side_changed = false;
        }
        return area;
    }

    bool changed() {
        return side_changed;
    }
};