class WordFilter {
  struct Node {
    std::vector<int> indices_;
    std::array<Node*, 26>* children_{nullptr};
  } prefix_, suffix_;
  
  template<typename It>
  void add(It begin, It end, int idx, Node* target) {
    for (; begin != end; ++begin) {
      if (!target->children_) target->children_ = new std::array<Node*, 26>{};
      Node* next = (*target->children_)[*begin - 'a'];
      if (!next) {
        next = new Node{};
        (*target->children_)[*begin - 'a'] = next;
      }
      target = next;
      target->indices_.push_back(idx);
    }
  }
  
  template<typename It>
  const std::vector<int>* find(It begin, It end, const Node* target) const {
    for (; begin != end; ++begin) {
      if (!target->children_) return nullptr;
      target = (*target->children_)[*begin - 'a'];
      if (!target) return nullptr;
    }
    return &target->indices_;
  }
  
public:
  WordFilter(const vector<string>& words) {
    for (int idx = 0; idx < words.size(); ++idx) {
      add(words[idx].cbegin(), words[idx].cend(), idx, &prefix_);
      add(words[idx].crbegin(), words[idx].crend(), idx, &suffix_);
    }
  }
    
  int f(const string& prefix, const string& suffix) {
    const auto* pre = find(prefix.cbegin(), prefix.cend(), &prefix_);
    if (!pre) return -1;
    const auto* suff = find(suffix.crbegin(), suffix.crend(), &suffix_);
    if (!suff) return -1;
    if (pre->size() > suff->size()) std::swap(pre, suff);
    for (auto it = pre->crbegin(); it != pre->crend(); ++it) {
      if (std::binary_search(suff->cbegin(), suff->cend(), *it)) return *it;
    }
    return -1;
  }
};