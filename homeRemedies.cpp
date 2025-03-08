#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to display remedies based on the selected disease and language
void displayRemedies(const string& disease, const string& language) {
    map<string, map<string, string>> remedies = {
        {"Heart Attack", {
            {"English", "CHEW ASPIRIN AND DRINK SOME LEMON WITH HONEY MIXING IN WATER."},
            {"Hindi", "एस्पिरिन चबाएं और पानी में शहद मिलाकर थोड़ा नींबू पिएं।"},
            {"Telugu", "ఆస్పిరిన్ నమిలి, నిమ్మకాయను తేనెతో నీటిలో కలిపి త్రాగండి."},
            {"Kannada", " ಆಸ್ಪಿರಿನ್ ಅಗಿಯಿರಿ ಮತ್ತು ಸ್ವಲ್ಪ ನಿಂಬೆಹಣ್ಣಿನ ಜೊತೆಗೆ ಜೇನುತುಪ್ಪವನ್ನು ನೀರಿನಲ್ಲಿ ಬೆರೆಸಿ ಕುಡಿಯಿರಿ."},
            {"Tamil", "ஆஸ்பிரின் மென்று சிறிது எலுமிச்சையை தண்ணீரில் தேன் கலந்து குடிக்கவும்."}  
             }},
        {"Lung Issues", {
            {"English", "Steam inhalation with eucalyptus oil."},
            {"Hindi", "यूकेलिप्टस तेल के साथ भाप लें।"},
            {"Telugu", "యుకలిప్టస్ నూనెతో పొగమంచు తీసుకోండి."},
            {"Kannada", "ಯೂಕಲಿಪ್ಟಸ್ ಎಣ್ಣೆ ಬಳಸಿಕೊಂಡು ಉಕ್ಕು ತೆಗೆದುಕೊಳ್ಳಿ."},
            {"Tamil", "யூகலிப்டஸ் எண்ணெயுடன் புகை பிடிக்கவும்."}
        }},
        {"Diabetes", {
            {"English", "Drink bitter gourd juice."},
            {"Hindi", "करेला का जूस पिएं।"},
            {"Telugu", "కర్రల కాయల రసం తాగండి."},
            {"Kannada", "ಕಡಲೆಕಾಯಿ ಹಣ್ಣುಗಳ ರಸ ಕುಡಿಯಿರಿ."},
            {"Tamil", "பிடிய கீரையை சாப்பிடுங்கள்."}
        }},
        {"High Blood Pressure", {
            {"English", "Eat bananas and dark chocolate."},
            {"Hindi", "केले और डार्क चॉकलेट खाएं।"},
            {"Telugu", "కెళ్లు మరియు డార్క్ చాక్లెట్ తినండి."},
            {"Kannada", "ಬಾಳೆಹಣ್ಣು ಮತ್ತು ಕಪ್ಪು ಚಾಕೊಲೇಟ್ ತಿನ್ನಿ."},
            {"Tamil", "வாழை மற்றும் கறுப்பு சாக்லேட் சாப்பிடுங்கள்."}
        }},
        {"Cold and Cough", {
            {"English", "Drink warm ginger tea."},
            {"Hindi", "गर्म अदरक की चाय पिएं।"},
            {"Telugu", "ఉష్ణంగా అల్లం చాయ్ తాగండి."},
            {"Kannada", "ಉಷ್ಣವಾದ ಅಳ್ಳಿಕಾಯಿ ಚಾಯ್ ಕುಡಿಯಿರಿ."},
            {"Tamil", "சூடான இஞ்சி தேநீர் குடிக்கவும்."}
        }},
        {"Fever", {
            {"English", "Stay hydrated and rest."},
            {"Hindi", "हाइड्रेटेड रहें और आराम करें।"},
            {"Telugu", "నీటిని తాగండి మరియు విశ్రాంతి తీసుకోండి."},
            {"Kannada", "ನೀರು ಕುಡಿಯಿರಿ ಮತ್ತು ವಿಶ್ರಾಂತಿ ತೆಗೆದುಕೊಳ್ಳಿ."},
            {"Tamil", "தண்ணீர் குடித்து ஓய்வெடுக்கவும்."}
        }},
        {"Headache", {
            {"English", "Apply a cold compress on your forehead."},
            {"Hindi", "अपने माथे पर ठंडी पट्टी लगाएं।"},
            {"Telugu", "మీ ముక్కు మీద చల్లని పట్టు పెట్టండి."},
            {"Kannada", "ನಿಮ್ಮ ಮುಕ್ಕಾಲಿಗೆ ತಂಪಾದ ಒತ್ತಣೆ ಹಾಕಿ."},
            {"Tamil", "உங்கள் முக்கால் மீது குளிர்ந்த கம்பளி வைக்கவும்."}
        }},
        {"Stomach Ache", {
            {"English", "Drink peppermint tea."},
            {"Hindi", "पुदीने की चाय पिएं।"},
            {"Telugu", "పుదీనా చాయ్ తాగండి."},
            {"Kannada", "ಪುದೀನಾ ಚಾಯ್ ಕುಡಿಯಿರಿ."},
            {"Tamil", "புதினா தேநீர் குடிக்கவும்."}
        }},
        {"Nausea", {
            {"English", "Ginger tea can help."},
            {"Hindi", "अदरक की चाय मदद कर सकती है।"},
            {"Telugu", "అల్లం చాయ్ సహాయపడుతుంది."},
            {"Kannada", "ಅಳ್ಳಿಕಾಯಿ ಚಾಯ್ ಸಹಾಯ ಮಾಡುತ್ತದೆ."},
            {"Tamil", "இஞ்சி தேநீர் உதவும்."}
        }},
        {"Allergies", {
                       {"English", "Honey can help reduce symptoms."},
            {"Hindi", "शहद लक्षणों को कम करने में मदद कर सकता है।"},
            {"Telugu", "తేనె లక్షణాలను తగ్గించడంలో సహాయపడుతుంది."},
            {"Kannada", "ಹೆಣ್ಣು ಲಕ್ಷಣಗಳನ್ನು ಕಡಿಮೆ ಮಾಡಲು ಸಹಾಯ ಮಾಡುತ್ತದೆ."},
            {"Tamil", "தேன் அறிகுறிகளை குறைக்க உதவும்."}
        }},
        {"Arthritis", {
            {"English", "Turmeric milk can help reduce inflammation."},
            {"Hindi", "हल्दी का दूध सूजन को कम कर सकता है।"},
            {"Telugu", "పసుపు పాలు వాపు తగ్గించడంలో సహాయపడుతుంది."},
            {"Kannada", "ಹಳದಿ ಹಾಲು ಉರಿಯೂಟವನ್ನು ಕಡಿಮೆ ಮಾಡಲು ಸಹಾಯ ಮಾಡುತ್ತದೆ."},
            {"Tamil", "மஞ்சள் பால் வீக்கம் குறைக்க உதவும்."}
        }},
        {"Insomnia", {
            {"English", "Drink warm milk before bed."},
            {"Hindi", "सोने से पहले गर्म दूध पिएं।"},
            {"Telugu", "నిద్రకు ముందు ఉష్ణ పాలు తాగండి."},
            {"Kannada", "ಮಲಗುವ ಮೊದಲು ಉಷ್ಣ ಹಾಲು ಕುಡಿಯಿರಿ."},
            {"Tamil", "மலக்கூட்டத்திற்கு முன்பு சூடான பால் குடிக்கவும்."}
        }},
        {"Acid Reflux", {
            {"English", "Chew gum to help with digestion."},
            {"Hindi", "पाचन में मदद के लिए चुइंगम चबाएं।"},
            {"Telugu", "జీర్ణక్రియకు సహాయపడటానికి గమ్ చీల్చండి."},
            {"Kannada", "ಜೀರ್ಣಕ್ರಿಯೆಗೆ ಸಹಾಯ ಮಾಡಲು ಚಪ್ಪಲಿ."},
            {"Tamil", "சீர்கேளிக்க உதவ கும்கம் நாக்கில் வைக்கவும்."}
        }},
        {"Skin Rashes", {
            {"English", "Apply aloe vera gel to soothe the skin."},
            {"Hindi", "त्वचा को ठंडा करने के लिए एलोवेरा जेल लगाएं।"},
            {"Telugu", "చర్మాన్ని చల్లగా ఉంచడానికి ఆలొవెరా జెల్ అప్లై చేయండి."},
            {"Kannada", "ಚರ್ಮವನ್ನು ಶೀತಲಗೊಳಿಸಲು ಆಲೋವೆರಾ ಜೆಲ್ ಹಚ್ಚಿ."},
            {"Tamil", "தோலையை அமைதியாக்க ஆலோவேரா ஜெல் தடவவும்."}
        }},
        {"Constipation", {
            {"English", "Increase fiber intake with fruits."},
            {"Hindi", "फलों के साथ फाइबर का सेवन बढ़ाएं।"},
            {"Telugu", "ఫలాలతో ఫైబర్ తీసుకోవడం పెంచండి."},
            {"Kannada", "ಹಣ್ಣುಗಳೊಂದಿಗೆ ಫೈಬರ್ ಸೇವನೆಯನ್ನು ಹೆಚ್ಚಿಸಿ."},
            {"Tamil", "பழங்களுடன் நார்ச்சத்து அதிகரிக்கவும்."}
        }},
        {"Back Pain", {
            {"English", "Apply a warm compress to the affected area."},
            {"Hindi", "प्रभावित क्षेत्र पर गर्म पट्टी लगाएं।"},
            {"Telugu", "ప్రభావిత ప్రాంతంలో ఉష్ణ పట్టు పెట్టండి."},
            {"Kannada", "ಪ್ರಭಾವಿತ ಪ್ರದೇಶದಲ್ಲಿ ತಂಪಾದ ಒತ್ತಣೆ ಹಾಕಿ."},
            {"Tamil", "பாதிக்கப்பட்ட பகுதியில் சூடான கம்பளி வைக்கவும்."}
        }},
        {"Fatigue", {
            {"English", "Stay hydrated and take short breaks."},
            {"Hindi", "हाइड्रेटेड रहें और छोटे ब्रेक लें।"},
            {"Telugu", "నీటిని తాగండి మరియు చిన్న విరామాలు తీసుకోండి."},
            {"Kannada", "ನೀರು ಕುಡಿಯಿರಿ ಮತ್ತು ಚಿಕ್ಕ ವಿರಾಮಗಳನ್ನು ತೆಗೆದುಕೊಳ್ಳಿ."},
            {"Tamil", "தண்ணீர் குடித்து சிறிய இடைவெளிகள் எடுக்கவும்."}
        }},
        {"Gastritis", {
            {"English", "Avoid spicy foods and drink chamomile tea."},
            {"Hindi", "मसालेदार खाद्य पदार्थों से बचें और कैमोमाइल चाय पिएं।"},
            {"Telugu", "మసాలా ఆహారాలను నివారించండి మరియు క్యామోమైల్ చాయ్ తాగండి."},
            {"Kannada", "ಮಸಾಲೆ ಆಹಾರಗಳನ್ನು ತಪ್ಪಿಸಿ ಕ್ಯಾಮೊಮೈಲ್ ಚಾಯ್ ಕುಡಿಯಿರಿ."},
                        {"Tamil", "மசாலா உணவுகளை தவிர்த்து காமோமில் தேநீர் குடிக்கவும்."}
        }},
        {"Sinusitis", {
            {"English", "Inhale steam with salt water."},
            {"Hindi", "नमक के पानी के साथ भाप लें।"},
            {"Telugu", "ఉప్పు నీటితో పొగమంచు తీసుకోండి."},
            {"Kannada", "ಉಪ್ಪು ನೀರಿನಿಂದ ಉಕ್ಕು ತೆಗೆದುಕೊಳ್ಳಿ."},
            {"Tamil", "உப்பு நீருடன் புகை பிடிக்கவும்."}
        }},
        {"Urinary Tract Infection", {
            {"English", "Drink plenty of water and cranberry juice."},
            {"Hindi", "बहुत सारा पानी और क्रैनबेरी का जूस पिएं।"},
            {"Telugu", "చాలా నీరు మరియు క్రాన్బెర్రీ రసం తాగండి."},
            {"Kannada", "ಬಹಳಷ್ಟು ನೀರು ಮತ್ತು ಕ್ರ್ಯಾನ್‌ಬೆರಿ ರಸ ಕುಡಿಯಿರಿ."},
            {"Tamil", "பல தண்ணீர் மற்றும் கிரான்பெரி ஜூஸ் குடிக்கவும்."}
        }},
        {"Anxiety", {
            {"English", "Practice deep breathing exercises."},
            {"Hindi", "गहरी सांस लेने के व्यायाम करें।"},
            {"Telugu", "గాఢ శ్వాస వ్యాయామాలు చేయండి."},
            {"Kannada", "ಗಾಢ ಉಸಿರಾಟ ವ್ಯಾಯಾಮಗಳನ್ನು ಮಾಡಿ."},
            {"Tamil", "ஆழமான மூச்சு பயிற்சிகளை செய்யவும்."}
        }},
        {"Depression", {
            {"English", "Engage in physical activity and sunlight."},
            {"Hindi", "शारीरिक गतिविधि और धूप में रहें।"},
            {"Telugu", "శారీరక కార్యకలాపాలు మరియు సూర్యరశ్మి పొందండి."},
            {"Kannada", "ಶಾರೀರಿಕ ಚಟುವಟಿಕೆ ಮತ್ತು ಸೂರ್ಯನ ಬೆಳಕು ಪಡೆಯಿರಿ."},
            {"Tamil", "உடற்பயிற்சி மற்றும் சூரிய ஒளியில் ஈடுபடவும்."}
        }},
        {"High Cholesterol", {
            {"English", "Eat more fruits and vegetables."},
            {"Hindi", "अधिक फल और सब्जियाँ खाएं।"},
            {"Telugu", "మరింత పండ్లు మరియు కూరగాయలు తినండి."},
            {"Kannada", "ಹೆಚ್ಚು ಹಣ್ಣುಗಳು ಮತ್ತು ತರಕಾರಿಗಳನ್ನು ತಿನ್ನಿ."},
            {"Tamil", "மேலும் பழங்கள் மற்றும் காய்கறிகள் சாப்பிடுங்கள்."}
        }},
        {"Osteoporosis", {
            {"English", "Consume foods rich in calcium."},
            {"Hindi", "कैल्शियम से भरपूर खाद्य पदार्थ खाएं।"},
            {"Telugu", "కేల్షియం అధికంగా ఉన్న ఆహారాలు తినండి."},
            {"Kannada", "ಕ್ಯಾಲ್ಸಿಯಂ ಸಮೃದ್ಧ ಆಹಾರಗಳನ್ನು ತಿನ್ನಿ."},
            {"Tamil", "கால்சியம் நிறைந்த உணவுகளை சாப்பிடுங்கள்."}
        }},
        {"Gout", {
            {"English", "Stay hydrated and avoid purine-rich foods."},
            {"Hindi", "हाइड्रेटेड रहें और प्यूरिन युक्त खाद्य पदार्थों से बचें।"},
            {"Telugu", "నీటిని తాగండి మరియు ప్యూరిన్ అధిక ఆహారాలను నివారించండి."},
            {"Kannada", "ನೀರು ಕುಡಿಯಿರಿ ಮತ್ತು ಪ್ಯೂರಿನ್ ಸಮೃದ್ಧ ಆಹಾರಗಳನ್ನು ತಪ್ಪಿಸಿ."},
            {"Tamil", "தண்ணீர் குடித்து பியூரின் நிறைந்த உணவுகளை தவிர்க்கவும்."}
        }},
        // Additional conditions
        {"Bleeding", {
            {"English", "Apply pressure to the wound and elevate the area."},
            {"Hindi", "घाव पर दबाव डालें और क्षेत्र को ऊँचा करें।"},
            {"Telugu", "గాయానికి ఒత్తిడి పెట్టండి మరియు ప్రాంతాన్ని ఎత్తండి."},
            {"Kannada", "ಗಾಯಕ್ಕೆ ಒತ್ತಣೆ ಹಾಕಿ ಮತ್ತು ಪ್ರದೇಶವನ್ನು ಎತ್ತಿ."},
            {"Tamil", "காயத்திற்கு அழுத்தம் கொடுத்து அந்த பகுதியை உயர்த்தவும்."}
        }},
        {"Burns", {
            {"English", "Cool the burn under running water."},
            {"Hindi", "जलती हुई जगह को बहते पानी के नीचे ठंडा करें।"},
            {"Telugu", "కలిగిన భాగాన్ని ప్రవహిస్తున్న నీటిలో చల్లగా చేయండి."},
                        {"Kannada", "ಕಾಯುವ ಭಾಗವನ್ನು ಹರಿಯುವ ನೀರಿನಲ್ಲಿ ತಂಪಾಗಿಡಿ."},
            {"Tamil", "காய்ந்த இடத்தை ஓடுகிற நீரில் குளிர்ந்துவிடுங்கள்."}
        }},
        {"Cuts", {
            {"English", "Clean the cut with soap and water, then apply a bandage."},
            {"Hindi", "कटी हुई जगह को साबुन और पानी से साफ करें, फिर पट्टी लगाएं।"},
            {"Telugu", "కటిన భాగాన్ని సబ్బు మరియు నీటితో శుభ్రం చేసి, తరువాత బాండేజ్ వేయండి."},
            {"Kannada", "ಕತ್ತರಿಸಿದ ಭಾಗವನ್ನು ಸಾಬೂನ್ ಮತ್ತು ನೀರಿನಿಂದ ಶುದ್ಧೀಕರಿಸಿ, ನಂತರ ಬಾಂಡ್ ಹಾಕಿ."},
            {"Tamil", "கட்டிய இடத்தை சோப்பு மற்றும் நீரால் சுத்தம் செய்து, பின்னர் பாண்டை போடவும்."}
        }},
        {"Rashes", {
            {"English", "Apply a cool compress and use anti-itch cream."},
            {"Hindi", "ठंडी पट्टी लगाएं और खुजली की क्रीम लगाएं।"},
            {"Telugu", "చల్లని పట్టు పెట్టండి మరియు కీళ్ల క్రీమ్ ఉపయోగించండి."},
            {"Kannada", "ತಂಪಾದ ಒತ್ತಣೆ ಹಾಕಿ ಮತ್ತು ಕೀಳ்மಟ್ಟ ಕ್ರೀಮ್ ಬಳಸಿ."},
            {"Tamil", "குளிர்ந்த கம்பளி வைக்கவும் மற்றும் கீறல் கிரீம் பயன்படுத்தவும்."}
        }},
        {"Fractures", {
            {"English", "Immobilize the area and seek medical help."},
            {"Hindi", "क्षेत्र को स्थिर करें और चिकित्सा सहायता प्राप्त करें।"},
            {"Telugu", "ప్రాంతాన్ని స్థిరంగా ఉంచండి మరియు వైద్య సహాయం పొందండి."},
            {"Kannada", "ಪ್ರದೇಶವನ್ನು ಸ್ಥಿರಗೊಳಿಸಿ ಮತ್ತು ವೈದ್ಯಕೀಯ ಸಹಾಯವನ್ನು ಪಡೆಯಿರಿ."},
            {"Tamil", "பகுதியை நிலைத்துவைத்து மருத்துவ உதவியை பெறவும்."}
        }},
    };

    if (remedies.find(disease) != remedies.end() && remedies[disease].find(language) != remedies[disease].end()) {
        cout << "Remedy for " << disease << " in " << language << ": " << remedies[disease][language] << endl;
    } else {
        cout << "Remedy not found for the selected disease and language." << endl;
    }
}

int main() {
    string diseases[] = {
        "Heart Attack", "Lung Issues", "Diabetes", "High Blood Pressure", "Cold and Cough",
        "Fever", "Headache", "Stomach Ache", "Nausea", "Allergies",
        "Arthritis", "Insomnia", "Acid Reflux", "Skin Rashes", "Constipation",
        "Back Pain", "Fatigue", "Gastritis", "Sinusitis", "Urinary Tract Infection",
        "Anxiety", "Depression", "High Cholesterol", "Osteoporosis", "Gout",
        "Bleeding", "Burns", "Cuts", "Rashes", "Fractures"
    };

    string languages[] = {"English", "Hindi", "Telugu", "Kannada", "Tamil"};

    cout << "Select a disease from the following list:" << endl;
    for (int i = 0; i < sizeof(diseases) / sizeof(diseases[0]); i++) {
        cout << i + 1 << ". " << diseases[i] << endl;
    }

    int diseaseChoice;
    cout << "Enter the number of your choice: ";
    cin >> diseaseChoice;

    if (diseaseChoice < 1 || diseaseChoice > sizeof(diseases) / sizeof(diseases[0])) {
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "Select a language:" << endl;
    for (int i = 0; i < sizeof(languages) / sizeof(languages[0]); i++) {
        cout << i + 1 << ". " << languages[i] << endl;
    }

    int languageChoice;
    cout << "Enter the number of your choice: ";
    cin >> languageChoice;

    if (languageChoice < 1 || languageChoice > sizeof(languages) / sizeof(languages[0])) {
        cout << "Invalid choice." << endl;
        return 1;
    }

    displayRemedies(diseases[diseaseChoice - 1], languages[languageChoice - 1]);

    return 0;
}