const durationPresets = { main: ['01', '30', '00'], set1: ['00', '20', '00'], set2: ['00', '45', '00'], set3: ['01', '15', '00'] };

function closeModal() { document.querySelector('.modal-overlay')?.remove(); }
function showModal(content, extraClass = '') {
  closeModal();
  const overlay = document.createElement('div');
  overlay.className = 'modal-overlay';
  overlay.innerHTML = `<section class="modal ${extraClass}" role="dialog" aria-modal="true">${content}</section>`;
  overlay.addEventListener('click', event => { if (event.target === overlay) closeModal(); });
  document.body.append(overlay);
  overlay.querySelector('[data-close]')?.focus();
}
function openDuration(name) {
  const [hours, minutes, seconds] = durationPresets[name] || durationPresets.main;
  const title = name === 'main' ? 'Set Main duration' : `Set Duration ${name.replace('set', '')}`;
  showModal(`<h2>${title}</h2><div class="duration-picker"><div><span>${hours === '00' ? '23' : '00'}</span><b>${hours}</b><span>${hours === '00' ? '01' : '02'}</span></div><i>:</i><div><span>${String(Number(minutes) - 1).padStart(2, '0')}</span><b>${minutes}</b><span>${String(Number(minutes) + 1).padStart(2, '0')}</span></div><i>:</i><div><span>59</span><b>${seconds}</b><span>01</span></div></div><div class="modal-actions"><button data-close>Cancel</button><button class="primary" data-confirm-duration>Confirm</button></div>`, 'duration-modal');
  document.querySelector('[data-close]').onclick = closeModal;
  document.querySelector('[data-confirm-duration]').onclick = closeModal;
}
function openConfirm(type) {
  const messages = {
    end: ['End this session?', 'This will stop your timer and save your progress', 'Cancel', 'End session', 'primary', 'session-summary.html'],
    quit: ['Quit this session?', '<span class="warning">⚠ Caution</span> : Your progress will not be saved', 'Keep studying', 'Quit session', 'danger', 'home.html'],
    changes: ['Save Changes?', 'You have unsaved changes.<br>Do you want to save before leaving?', 'Keep editing', 'Discard', 'danger', 'home.html']
  };
  const [title, description, cancel, action, style, href] = messages[type];
  const save = type === 'changes' ? '<button class="primary" data-save>Save changes</button>' : '';
  showModal(`<h2>${title}</h2><p>${description}</p><div class="modal-actions"><button data-close>${cancel}</button><button class="${style}" data-action>${action}</button>${save}</div>`);
  document.querySelector('[data-close]').onclick = closeModal;
  document.querySelector('[data-action]').onclick = () => location.href = href;
  document.querySelector('[data-save]')?.addEventListener('click', () => location.href = href);
}
document.addEventListener('click', event => {
  const duration = event.target.closest('[data-duration]');
  const confirm = event.target.closest('[data-confirm]');
  if (duration) openDuration(duration.dataset.duration);
  if (confirm) { event.preventDefault(); openConfirm(confirm.dataset.confirm); }
});
document.addEventListener('keydown', event => { if (event.key === 'Escape') closeModal(); });
