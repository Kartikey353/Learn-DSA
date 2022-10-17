//in an undirected graph with maximum degree n, find a graph coloring  using at max n+1 colors.
class GraphNode{
private:
    string label_;
    unordered_set<GraphNode*> neighbors_;
    string color_;

public:
    GraphNode(const string& label) :
        label_(label),
        neighbors_(),
        color_()
    {
    }

    const string& getLabel() const{
        return label_;
    }

    const unordered_set<GraphNode*> getNeighbors() const
    {
        return neighbors_;
    }

    void addNeighbor(GraphNode& neighbor){
        neighbors_.insert(&neighbor);
    }

    bool hasColor() const{
        return !color_.empty();
    }

    const string& getColor() const{
        if (hasColor()) {
            return color_;
        }
        else {
            throw logic_error("GraphNode is not marked with color");
        }
    }

    void setColor(const string& color){
        color_ = color;
    }
};

GraphNode a("a");
GraphNode b("b");
GraphNode c("c");

a.addNeighbor(b);
b.addNeighbor(a);
b.addNeighbor(c);
c.addNeighbor(b);

vector<GraphNode*> graph { &a, &b, &c };
