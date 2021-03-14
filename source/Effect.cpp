#include <EffectBase.hpp>

namespace Effects
{
	/**
	 * Simple Volume effect example.
	 */
	class Volume : public EffectBase
	{
	public:
		Volume()
			: 
			// Initialize the volume knob
			m_Volume(Parameter("Volume", ParameterType::Knob)),
			EffectBase("Volume")
		{
			// Set the height of the effect to 80.
			Height(80);

			// Some settings for the volume knob
			m_Volume.Size({ 30, 30 });
			m_Volume.Range({ 0, 100 });
			m_Volume.Unit("%");
			m_Volume.Decimals(1);			
			m_Volume.ResetValue(100);
			m_Volume.ResetValue();
			m_Volume.Multiplier(0.4);
			
			// Put the volume knob in the center of the entire Div.
			Div().Align(Div::Alignment::Center);
			Div() = m_Volume;
		}

		float NextSample(float in, int c) 
		{
			// Multiply the incoming sample with the volume knob
			return in * m_Volume.Value() * 0.01;
		}

		operator nlohmann::json() 
		{
			// Save the value of the volume knob.
			nlohmann::json _json = nlohmann::json::object();
			_json["volume"] = m_Volume.Value();
			return _json;
		}

		void operator=(const nlohmann::json& json)
		{
			// Load the value of the volume knob.
			m_Volume.Value(json.at("volume").get<double>());
		}

	private:

		// The volume parameter
		Effects::Parameter& m_Volume;
	};
}

/**
 * MAKE SURE TO ADD THIS METHOD!!
 * This allows the Gui to create an instance of the effect.
 */
extern "C"
{
	DLLDIR void* NewInstance()
	{
		return new Effects::Volume();
	}
}