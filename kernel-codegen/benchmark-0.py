from RF_dump import dump_RF
from utils_graph import RF_check

dump_RF(exploration = "benchmark-0", kernel = "DT-Naive")
dump_RF(exploration = "benchmark-0", kernel = "DT-Loop")
dump_RF(exploration = "benchmark-0", kernel = "DT-Rec")
dump_RF(exploration = "benchmark-0", kernel = "DT-Arr-Baseline")
dump_RF(exploration = "benchmark-0", kernel = "DT-Arr-Shiftless")
dump_RF(exploration = "benchmark-0", kernel = "DT-Arr-Stallfree")

RF_check(exploration = "benchmark-0",test_number = 0)