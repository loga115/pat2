#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

struct Point {
    int x, y;
};

struct Segment {
    Point p1, p2;
    int id;
};

struct Event {
    int x;
    Segment segment;
    bool isStart;
};

bool compareEvents(const Event &e1, const Event &e2) {
    if (e1.x == e2.x) {
        return e1.isStart > e2.isStart;
    }
    return e1.x < e2.x;
}

bool doIntersect(const Segment &s1, const Segment &s2) {
    auto orientation = [](const Point &p, const Point &q, const Point &r) {
        int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); // cross product
        if (val == 0) return 0; // collinear
        return (val > 0) ? 1 : 2; // clock or counterclock wise
    };

    auto onSegment = [](const Point &p, const Point &q, const Point &r) {
        if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
            q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
            return true;
        return false;
    };

    Point p1 = s1.p1, q1 = s1.p2, p2 = s2.p1, q2 = s2.p2;

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

struct CompareSegments {
    bool operator()(const Segment &s1, const Segment &s2) const {
        // Implement comparison logic for segments in the BST
        // This should compare the y-coordinates of the segments at the current sweep line position
    }
};

std::vector<std::pair<Segment, Segment>> findIntersections(const std::vector<Segment> &segments) {
    std::vector<Event> events;
    for (const auto &segment : segments) {
        events.push_back({segment.p1.x, segment, true});
        events.push_back({segment.p2.x, segment, false});
    }

    std::sort(events.begin(), events.end(), compareEvents);

    std::set<Segment, CompareSegments> activeSegments;
    std::vector<std::pair<Segment, Segment>> intersections;

    for (const auto &event : events) {
        if (event.isStart) {
            auto it = activeSegments.lower_bound(event.segment);
            if (it != activeSegments.end() && doIntersect(*it, event.segment)) {
                intersections.push_back({*it, event.segment});
            }
            if (it != activeSegments.begin() && doIntersect(*std::prev(it), event.segment)) {
                intersections.push_back({*std::prev(it), event.segment});
            }
            activeSegments.insert(event.segment);
        } else {
            auto it = activeSegments.find(event.segment);
            if (it != activeSegments.end()) {
                if (it != activeSegments.begin() && std::next(it) != activeSegments.end() && doIntersect(*std::prev(it), *std::next(it))) {
                    intersections.push_back({*std::prev(it), *std::next(it)});
                }
                activeSegments.erase(it);
            }
        }
    }

    return intersections;
}

int main() {
    std::vector<Segment> segments = {
        {{1, 1}, {4, 4}, 1},
        {{1, 4}, {4, 1}, 2},
        {{2, 2}, {6, 2}, 3},
        {{5, 1}, {5, 5}, 4}
    };

    auto intersections = findIntersections(segments);

    for (const auto &pair : intersections) {
        std::cout << "Segment " << pair.first.id << " intersects with Segment " << pair.second.id << std::endl;
    }

    return 0;
}