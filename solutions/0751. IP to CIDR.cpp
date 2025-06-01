class Solution {
private:
    vector<int> parse(string& ip) {
        vector<int> parts;
        int part = 0;
        for (char ch: ip) {
            if (ch == '.') {
                parts.push_back(part);
                part = 0;
            } else {
                part = part * 10 + (ch - '0');
            }
        }
        parts.push_back(part);

        return parts;
    }

    uint getAddress(vector<int>& parts) {
        uint address = 0;
        for (int part: parts) {
            address = (address << 8) | part;
        }
        return address;
    }

    int getAddresses(int address) {
        int bits = 0;
        for (int i = 0; i < 11; i++) {
            if (address & (1 << i)) {
                break;
            }
            bits++;
        }

        return 1 << bits;
    }

    vector<pair<uint, int>> getCIDRs(uint address, int target) {
        int left = target;
        vector<pair<uint, int>> cidrs;
        
        while (left > 0) {
            int numAddresses = getAddresses(address);
            int possible = min(numAddresses, left);

            for (int i = 11; i >= 0; i--) {
                if (possible & (1 << i)) {
                    int size = (1 << i);
                    cidrs.push_back({address, 32 - i});
                    address += size;
                }
            }

            left -= possible;
        }

        return cidrs;
    }

    string addressToIP(uint address) {
        int mask = (1 << 8) - 1;
        string ip = "";
        for (int i = 0; i < 4; i++) {
            ip = to_string(address & mask) + 
                 (i ? "." : "") +
                 ip;
            address >>= 8;
        }
        return ip;
    }

    vector<string> formatCIDRs(vector<pair<uint, int>>& cidrs) {
        vector<string> ans;
        for (auto cidr: cidrs) {
            ans.push_back(addressToIP(cidr.first) + "/" + to_string(cidr.second));
        }
        return ans;
    }

public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<int> parts = parse(ip);
        uint address = getAddress(parts);
        vector<pair<uint, int>> cidrs = getCIDRs(address, n);

        return formatCIDRs(cidrs);
    }
};
