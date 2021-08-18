#include "LaneMapContainer.h"

#include "swss/logger.h"

using namespace saivs;

bool LaneMapContainer::insert(
        _In_ std::shared_ptr<LaneMap> laneMap)
{
    SWSS_LOG_ENTER();

    auto idx = laneMap->getSwitchIndex();

    if (m_map.find(idx) != m_map.end())
    {
        SWSS_LOG_ERROR("map for switch index %u already exists", idx);

        return false;
    }

    m_map[idx] = laneMap;

    return true;
}

bool LaneMapContainer::remove(
        _In_ uint32_t switchIndex)
{
    SWSS_LOG_ENTER();

    auto it = m_map.find(switchIndex);

    if (it != m_map.end())
    {
        m_map.erase(it);

        return true;
    }

    return false;
}

std::shared_ptr<LaneMap> LaneMapContainer::getLaneMap(
        _In_ uint32_t switchIndex) const
{
    SWSS_LOG_ENTER();

    auto it = m_map.find(switchIndex);

    if (it == m_map.end())
    {
        return nullptr;
    }

    return it->second;
}

void LaneMapContainer::clear()
{
    SWSS_LOG_ENTER();

    m_map.clear();
}

bool LaneMapContainer::hasLaneMap(
        _In_ uint32_t switchIndex) const
{
    SWSS_LOG_ENTER();

    return m_map.find(switchIndex) != m_map.end();
}

size_t LaneMapContainer::size() const
{
    SWSS_LOG_ENTER();

    return m_map.size();
}

void LaneMapContainer::removeEmptyLaneMaps()
{
    SWSS_LOG_ENTER();

    for (auto it = m_map.begin(); it != m_map.end();)
    {
        if (it->second->isEmpty())
        {
            it = m_map.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
