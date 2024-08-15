#include <behaviortree_cpp_v3/bt_factory.h>
#include <iostream>

class SayHello : public BT::SyncActionNode
{
public:
    SayHello(const std::string& name) : BT::SyncActionNode(name, {}) {}
    BT::NodeStatus tick() override
    {
        std::cout << "Hello!" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class SayGoodbye : public BT::SyncActionNode
{
public:
    SayGoodbye(const std::string& name) : BT::SyncActionNode(name, {}) {}
    BT::NodeStatus tick() override
    {
        std::cout << "Goodbye!" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

int main(int argc, char **argv)
{
    BT::BehaviorTreeFactory factory;

    factory.registerNodeType<SayHello>("SayHello");
    factory.registerNodeType<SayGoodbye>("SayGoodbye");

    auto tree = factory.createTreeFromFile("src/my_behavior_tree/simple_tree.xml");


    //BT::TreeViewer viewer(tree);
    //viewer.show();

    // Você pode adicionar um loop para atualizar a visualização
    // conforme o nó é executado
    while (true) {
        tree.tickRoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}